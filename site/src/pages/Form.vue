<template>
    <div class="form-app">
        <h1>Junta-te à nossa newsletter!</h1>
        <iframe src="https://docs.google.com/forms/d/e/1FAIpQLSfsp2p67Z-M-XnN81b4g0fZR3JWDaudtpTfwqLyfvaYVOp5TQ/viewform?embedded=true" width="640" height="851" frameborder="0" marginheight="0" marginwidth="0">A carregar…</iframe>
    </div>
</template>

<script>

export default {
  name: "form-page",
  data() {
      return {
        initialized: false,
      
      }
  }
};
</script>

<style scoped>
    @import url('https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500&display=swap');

    .form-app{
    padding-top: 4vw;
    padding-bottom: 12vw;
    font-family: Roboto;
    } 
</style>