<template>
    <div class="error-comp">
        <div>
            <img src="https://clipart.info/images/ccovers/1496175203emoji-android-heavy-exclamation-mark-symbol.png">
        </div>
        <div class="error-msg">A redirecionar para a drive<p>Por favor aguarda</p></div>
    </div>
</template>

<script>

import PulseLoader from '../../node_modules/vue-spinner/src/PulseLoader.vue';
export default {
  name: "projects-page",
  data() {
      return {
        initialized: false,
      }
  },
  components:{
    PulseLoader
},
  mounted(){
  },
  created(){
         window.location.href = "https://drive.google.com/open?id=1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz";
    }
};
</script>

<style>
.error-comp {
    height: 78vh;
    padding-top:200px;
}
.error-msg {
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  font-family: 'Lato';
  margin-top: 20px;
  font-size: 25px;
  font-weight: normal;
  font-style: normal;
  font-stretch: normal;
  line-height: 35px;
  letter-spacing: normal;
  color: #505050;
  display: inline-block;
}
</style>