<template>
    <div class="oportunities-app" :style="{padding: '10px', paddingBottom: '200px', fontFamily: 'Roboto'}">

       <div class="description-opportunities">
           <div class="opportunities-text">
                <div class="description-title">
                    Oportunidades
                </div>
                <div class="description-text">Desde estágios até vagas de emprego, conhece aqui as melhores oportunidades!
                </div>
            </div>
            <img src="../assets/oportunities.jpg"/>
        </div>

        <div class="team" v-if="initialized">
             <ul v-if="cardList && cardList.length" style="list-style: none;display: flex; flex-direction: row; flex-wrap: wrap;">
                <li v-for="(card,card_id) in cardList" :key="card_id" style=" flex: 0 1 50%;padding-bottom: 10px;">
                    <div class="card" >       
                        <h2>{{card.name}}</h2>
                        <p><span v-html="card.desc"/></p>
                    </div>
                </li>
            </ul>
        </div>
        <div v-else>
            <PulseLoader :color="'#009DE0'"></PulseLoader>
        </div>
    </div>
</template>

<script>
import axios from 'axios';
import PulseLoader from 'vue-spinner/src/PulseLoader.vue';

export default {
    name: "oportunities-page",
    data() {
        return {
            initialized: false,
            cardList: []
        };
    },
    created() {
        axios.get("https://api.trello.com/1/lists/620256ba93c9f35b1c4c54ac/cards?attachments=true")
            .then(response => {
            for (var i = 0; i < response.data.length; i++) {
                this.cardList.push({ id: i, name: response.data[i].name, url: response.data[i].attachments[0].url, desc: response.data[i].desc });
            }
        }).finally(() => {
            this.initialized = true;
        });
    },
    methods: {
        curateCardText(List) {
            List.forEach(element => {
                element.desc = this.linkify(element.desc);
            });
        },
        linkify(inputText) {
            //eslint-disable-next-line
            const pattern1 = /(\b(https?|ftp):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/gim;
            let text = inputText.replace(pattern1, "<a href=\"$1\" target=\"_blank\">$1</a>");
            //eslint-disable-next-line
            const pattern2 = /(^|[^\/])(www\.[\S]+(\b|$))/gim;
            text = text.replace(pattern2, "$1<a href=\"http://$2\" target=\"_blank\">$2</a>");
            return text;
        }
    },
    components: { PulseLoader }
};
</script>

<style scoped>
.description-opportunities{
    padding-top: 100px;
    height: 300px;
    background-color:white;
    position: relative;
}

.card {
    background: white;
    border-radius: 5px;
    box-shadow: 0 4px 8px 0 rgb(0 0 0 / 20%), 0 6px 20px 0 rgb(0 0 0 / 19%);
    text-align: center;
    padding: 5px;
    margin: 10px;
    white-space: pre-wrap;
    padding-left: 20px;
    padding-right: 20px;
    height: 100%;
    box-sizing: border-box;
}
.description-opportunities img{
    width: 700px;
    /*transform: rotate(30deg);*/
    clip-path: inset(0 5.5em 4.5em 3em);
    position: absolute;
    top:100px;
    left: -60px;
    z-index: 0;
}
.opportunities-text{
    float: right;
    padding-right: 40px;
    position: relative;
    z-index: 1;
}
.description-title{
    font-family: 'Raleway', sans-serif;
    font-size: 50px;
    font-weight: bolder;
    color: #505050;
    text-align: right;
    padding-top: 30px;
}
.description-text{
    margin-top: 10px;
    background-color: #009DE0;
    border-radius: 5px;
    font-size: 30px;
    font-family: 'Karla';
    width: 750px;
    padding-right: 40px;
    padding-top: 15px;
    padding-bottom: 15px;
    margin-right: -40px;
    text-align: right;
    color: #ffffff;
    line-height: 50px;
}
.team{
    padding: 15px;
    background-color: #ecf7ff;
}
.team-flex{
    padding-left: 50px;
    padding-right: 50px;
    display: flex;
    flex-wrap: wrap;
    justify-content: space-around;
    margin-right: 8vw;
    margin-left: 8vw;
    margin-top: 30px;
}
.teams_container {
    position: relative;
    height: auto;
    width: auto;
}
.linkedin-icons {
    opacity: 0;
    position:absolute;
    top:-75px;
    left:0px;
    right:85px;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.insta-icons {
    opacity: 0;
    position:absolute;
    top:-75px;
    left:85px;
    right:0;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.git-icons {
    opacity: 0;
    position:absolute;
    top:75px;
    left:85px;
    right:0;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.mail-icons {
    opacity: 0;
    position:absolute;
    top:75px;
    left:-85px;
    right:0;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.teams_container:hover .git-icons,
.teams_container:hover .mail-icons,
.teams_container:hover .insta-icons,
.teams_container:hover .linkedin-icons {
  opacity: 1;
}
.team-member-name {
    display: flex;
    flex-direction: row;
    justify-content: space-around;
}
.team-member {
    transition: .5s ease;
}
.team-member img{ 
    height: 220px;
    width: 220px;
    margin-right: 10px;
    margin-left: 10px;
}
.teams_container:hover .team-member {
  opacity: 0.5;
}
.member-name{
    width: 100px;
    font-size: 22px;
    text-align: center;
    font-family:'Lato', sans-serif;
    color: #262626;
}
.icon-team-member {
    height: 60px;
}
@media screen and (max-width: 1200px) {
    .team-flex {
        padding-left: 12px;
        margin-right: 5vw;
        margin-left: 5vw;
    }
}
@media screen and (max-width: 800px) {
    .description-title{
        font-size: 40px;
    }
    .description-text{
        font-size: 18px;
        width: 320px;
        padding-right: 40px;
        line-height: 28px;
    }
    .description-opportunities img{
        width: 475px;
        top: 200px;
    }
    
    .team-flex {
        padding-left: 12px;
        margin-right: 5vw;
        margin-left: 5vw;
    }
    .team-flex img{
        height: 140px;
        width: 140px;
        margin-top: 30px;
        flex: 0 0 50%;
        margin-right: 10px;
    }
    .member-name{
        font-size: 17px;
        margin-left:13%;
    }
    .icon-team-member {
        height: 40px !important;
        width: 40px !important;
        margin-top: 20px !important;
        margin-right: 0px !important;
    }
}
@media screen and (max-width: 400px) {
    .description-opportunities{
        height: 200px;
        background-color:white;
        position: relative;
    }
    .description-title{
        font-size: 30px;
        padding-top: 10px;
    }
    .description-text{
        font-size: 16px;
        width: 250px;
        padding-right: 30px;
        padding-left: 20px;
        line-height: 24px;
    }
    .description-opportunities img{
        width: 475px;
        top: 150px;
    }
    .team{
        padding-top: 20px;
    }
    
    .team-flex {
        margin-right: 2vw;
        margin-left: 2vw;
    }
    .team-flex img{
        height: 120px;
        width: 120px;
        margin-top: 5px;
        flex: 0 0 50%; margin-right: 10px;
    }
    .member-name{
        margin-left:6%;
    }
}
</style>