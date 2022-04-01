<template>
    <Loader v-if="loading"/>
    <div v-else class="results_table">
        <div class="general_table">
            <caption>Geral</caption>
            <sub v-if="showGeneral"> Top {{showGeneral}} </sub>
            <table :style="{width: tablesWidth + '%'}">
                <tr class="table_header">
                    <th v-for="h in header" :key="h">{{h}}</th>
                </tr>
                <tr v-for="general in generalList" :key="general">
                    <td v-for="field in general" :key="field">{{field}}</td>
                </tr>
            </table>
        </div>
        <div v-if="dayList.length > 0" class="daily_table">
            <caption>{{dayShow}}</caption>
            <sub v-if="showDaily"> Top {{showDaily}} </sub>
            <table :style="{width: tablesWidth + '%'}">
                <tr class="table_header">
                    <th v-for="h in header" :key="h">{{h}}</th>
                </tr>
                <tr v-for="day in dayList" :key="day">
                    <td v-for="field in day" :key="field">{{field}}</td>
                </tr>
            </table>
        </div>
    </div>
</template>

<script>
import axios from 'axios';
import Loader from './Loader';

export default {
    name: "competition-tables-component",
    components: {
      Loader,
    },
    props:{
        file:{
            type:String,
            default: null
        },
        end_column:{
            type:String,
            default: 'J'
        },
        sortDia:{
            type:String,
            default: 'Dia'
        },
        sortScore:{
            type:String,
            default: 'Score'
        },
        showDaily:{
            type:Number,
            default: null
        },
        showGeneral:{
            type:Number,
            default: null
        },
        showColumns:{
            type:Array,
            default:null
        },
        tablesWidth:{
            type:Number,
            default:45
        },
        accumulation:{
            type:Boolean,
            default:false
        },
        accumulationField:{
            type:String,
            default:null
        }
    },
    data(){
        return{
            api: {
                baseUrl: 'https://sheets.googleapis.com/v4/spreadsheets/'+this.file+'/values:batchGet?ranges=A1%3A'+this.end_column+'&valueRenderOption=FORMATTED_VALUE&key=AIzaSyBesotaNgSaTUIhrSKjEaExdi-ksKInhoE',
            },
            entries: [],
            header: [],
            not_header: [],
            allDayList: [],
            dayList: [],
            generalList: [],
            loading:true,
            day: null,
            dayShow: null
        }
    },
    created(){
        this.getData(this.api.baseUrl)
    },
    methods: {
        createDate(){
            const days_ext = ['Domingo','Segunda','Terça','Quarta','Quinta','Sexta','Sábado'];
            const days_numb = ['D',2,3,4,5,6,'S'];
            const current = new Date();
            this.day=current.getDay();
            this.dayShow = days_ext[this.day];
            var buffer=[];
            this.dayList.forEach( element =>{
                if(element[this.sortDia] === days_ext[this.day] || element[this.sortDia] == days_numb[this.day]){
                    buffer.push(element)
                }
            })
            this.dayList=buffer;
        },
        getData(apiUrl) {
            axios.get(apiUrl).then((res) => {
                this.entries = res.data.valueRanges[0].values;
                this.header = this.entries.shift();
                this.entries = this.objectifier(this.entries,this.header);
                this.allDayList = this.sortArray(this.entries,this.sortDia);
                this.dayList = this.sortArray(this.entries,this.sortScore);
                this.generalList = JSON.parse(JSON.stringify(this.dayList));
                if(this.accumulation){
                    this.generalList = this.accumulateResults(this.generalList);
                    this.generalList = this.sortArray(this.generalList,this.sortScore);
                }
                this.beautifyHeader();
                this.createDate();
                this.dayList = this.beautifyTables(this.dayList,this.showDaily);
                this.generalList = this.beautifyTables(this.generalList,this.showGeneral);
                this.entries = []
                this.not_header = []
                this.loading=false
            });
        },
        sortArray(init_arr,field){
            var buffer=[...init_arr].sort(function(a, b){return b[field] - a[field]});
            return buffer;
        },
        objectifier(array,sorter){
            var arr=[]
            array.forEach( entry => {
                var line={}
                entry.forEach( (element,index) => {
                    line[sorter[index]] = element
                })
                arr.push(line)
            })
            return arr;
        },
        beautifyHeader(){
            this.not_header = this.header.filter( element => !this.showColumns.includes(element))
            this.header = this.header.filter( element => this.showColumns.includes(element))
        },
        beautifyTables(array,amount_of_entries){
            if(amount_of_entries){
                array=array.slice(0, amount_of_entries);
            }
            array.forEach( element => {
                this.not_header.forEach( remover =>{
                    delete element[remover]
                })
            })
            return array;
        },
        accumulateResults(array){
            var final_array = [];
            var buffer=array;
            buffer = this.sortArray(buffer,this.accumulationField)
            var to_accumulate=buffer[0];
            var accumulated = 0;
            buffer.forEach(element =>{
                if(element[this.accumulationField]===to_accumulate[this.accumulationField]){
                    accumulated = accumulated + parseInt(element[this.sortScore]);
                }else{
                    to_accumulate[this.sortScore] = accumulated;
                    final_array.push(to_accumulate);
                    to_accumulate = element;
                    accumulated = parseInt(element[this.sortScore]);
                }
            })
            return final_array;
        }
    }
}
</script>

<style scoped>
*{
    box-sizing: border-box;
}
.results_table{
    display: flex;
    justify-content: center;
}
.general_table{
    flex: 45%;
    padding: 5px;
}
.daily_table{
    flex: 45%;
    padding: 5px;
}
table {
    margin: 0 auto;
    border-collapse: collapse;
    border-spacing: 0;
    width: 45%;
    border: 1px solid #ddd;
}
caption {
    display: flex;
    align-items: center;
    justify-content: center;
    font-family:consolas;
    font-size: 2rem;
    font-weight:300;
    letter-spacing:1px;
    white-space: nowrap;
    transform: translate(0%, -50%);
    font-variation-settings: 'wght';
    margin: 0;
    animation: rise 2.25s infinite ease-in-out;
    -webkit-animation: rise 2.25s infinite ease-in-out;
    -moz-animation: rise 2.25s infinite ease-in-out;
}
sub {
    display: flex;
    align-items: center;
    justify-content: center;
    font-family:consolas;
    font-size: 1rem;
    font-weight:150;
    letter-spacing:1px;
    white-space: nowrap;
    transform: translate(0%, -50%);
    font-variation-settings: 'wght';
    margin: 0;
    animation: rise 2.25s infinite ease-in-out;
    -webkit-animation: rise 2.25s infinite ease-in-out;
    -moz-animation: rise 2.25s infinite ease-in-out;
}
th, td {
  text-align: center;
  padding: 15px;
}
tr:nth-child(odd) {
  background-color: #f2f2f2;
}
tr:nth-child(even) {
  background-color: #27ade4;
}
.table_header{
    background: linear-gradient(90deg, rgba(0,121,173,1) 0%, rgba(0,157,224,1) 0%);
    border: 1px solid;
}
tr:nth-child(2){
    background: radial-gradient(ellipse farthest-corner at right bottom, #FEDB37 0%, #FDB931 8%, #9f7928 30%, #8A6E2F 40%, transparent 80%),
                radial-gradient(ellipse farthest-corner at left top, #FFFFFF 0%, #FFFFAC 8%, #D1B464 25%, #5d4a1f 62.5%, #5d4a1f 100%);
    -webkit-animation: Gold 3s ease infinite;
    -moz-animation: Gold 3s ease infinite;
    animation: Gold 3s ease infinite;
}
tr:nth-child(3){
    background: radial-gradient(ellipse farthest-corner at right bottom, #FFFFFF 0%, #e9e7e0 15%, #dad8d1 30%, #BEBDB8 40%, transparent 80%),
                radial-gradient(ellipse farthest-corner at left top, #FFFFFF 0%, #f1f1f1 15%, #c9c0bb 30%, silver 60%, silver 80%);
    -webkit-animation: Silver 5s ease infinite;
    -moz-animation: Silver 5s ease infinite;
    animation: Silver 5s ease infinite;
}
tr:nth-child(4){
    background: radial-gradient(ellipse farthest-corner at right bottom, #dca570 0%, #d7995b 8%, #cd7f32 30%, #b9722d 40%, transparent 80%),
                radial-gradient(ellipse farthest-corner at left top, #dca570 0%, #d7995b 8%, #d28c47 30%, #905923 62.5%, #905923 100%);
    -webkit-animation: Bronze 10s ease infinite;
    -moz-animation: Bronze 10s ease infinite;
    animation: Bronze 10s ease infinite;
}

@keyframes rise {
  50% {
    font-variation-settings: 'wght' var(--upper);
    color: hsla(180, 100%, 100%, var(--alpha-u));
    transform: translate(0, -15%);
  }
}
@-webkit-keyframes rise {
  50% {
    font-variation-settings: 'wght' var(--upper);
    color: hsla(180, 100%, 100%, var(--alpha-u));
    transform: translate(0, -15%);
  }
}
@-moz-keyframes rise {
  50% {
    font-variation-settings: 'wght' var(--upper);
    color: hsla(180, 100%, 100%, var(--alpha-u));
    transform: translate(0, -15%);
  }
}
@-webkit-keyframes Gold {
    0%{filter: brightness(100%)}
    50%{filter: brightness(110%)}
    100%{filter: brightness(100%)}
}
@-moz-keyframes Gold {
    0%{filter: brightness(100%)}
    50%{filter: brightness(110%)}
    100%{filter: brightness(100%)}
}
@keyframes Gold {
    0%{filter: brightness(100%)}
    50%{filter: brightness(110%)}
    100%{filter: brightness(100%)}
}

@-webkit-keyframes Silver {
    0%{filter: brightness(100%)}
    25%{filter: brightness(95%)}
    50%{filter: brightness(90%)}
    75%{filter: brightness(95%)}
    100%{filter: brightness(100%)}
}
@-moz-keyframes Silver {
    0%{filter: brightness(100%)}
    25%{filter: brightness(95%)}
    50%{filter: brightness(90%)}
    75%{filter: brightness(95%)}
    100%{filter: brightness(100%)}
}
@keyframes Silver {
    0%{filter: brightness(100%)}
    25%{filter: brightness(95%)}
    50%{filter: brightness(90%)}
    75%{filter: brightness(95%)}
    100%{filter: brightness(100%)}
}

@-webkit-keyframes Bronze {
    0%{filter: brightness(100%)}
    50%{filter: brightness(80%)}
    100%{filter: brightness(100%)}
}
@-moz-keyframes Bronze {
    0%{filter: brightness(100%)}
    50%{filter: brightness(80%)}
    100%{filter: brightness(100%)}
}
@keyframes Bronze {
    0%{filter: brightness(100%)}
    50%{filter: brightness(80%)}
    100%{filter: brightness(100%)}
}

@media screen and (max-width: 600px) {
  .general_table {
    width: 100%;
  }
  .daily_table {
    width: 100%;
  }
}
</style>