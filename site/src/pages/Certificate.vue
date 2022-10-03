<template>
    <div class="certificate-app">
        <div v-if="initialized">
<h2>Certificado de Participação</h2>
<div>
    <img :src='certificateUrl' alt="certificate Image">
</div>
</div>
    <div v-else>
      <PulseLoader :color="'#009DE0'"></PulseLoader>
    </div>
        
        <div>{{this.error}}</div>
    </div>
</template>

<script>
import axios from 'axios';
import PulseLoader from 'vue-spinner/src/PulseLoader.vue';

export default {
  name: "certificate-page",
  components: {
    PulseLoader
},
  data() {
      return {
        initialized: false,
        error: null,
        certificateUrl: null
      }
  },created(){
    console.log("https://api.trello.com/1/cards/" +this.$route.params.id +"?attachments=true")
        axios.get("https://api.trello.com/1/cards/" +this.$route.params.id +"?attachments=true")
        .then(response => {
            console.log(response.data)
            this.certificateUrl = response.data.attachments[0].url
        }).catch (() => {
            this.error = "Unable to find certificate"
        }).finally(()=>{
          this.initialized = true
        });
    }
};
</script>

<style scoped>
    @import url('https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500&display=swap');
   .contacts-comp {
	position: unset;
    }
    .certificate-app{
    padding-top: 10vh;
    padding-bottom: 7vh;
    font-family: Roboto;
    } 
    .certificate-app img{
	width: 80vw;
	box-shadow: 0 0 7px 3px #888;
    }
   @media only screen and (max-width: 1080px){
    .certificate-app {
         padding-top: 80px;
    }
   }
</style>
<style>


@media only screen and (max-width: 1080px){
    .contacts-comp .row .col-md-4:first-child {
         display: none;
    }
   }
.contacts-comp {
	position: unset;
}
</style>
