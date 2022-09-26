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

    .certificate-app{
    padding-top: 4vw;
    padding-bottom: 12vw;
    font-family: Roboto;
    } 
</style>