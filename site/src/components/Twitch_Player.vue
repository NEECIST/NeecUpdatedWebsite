<template>
  <iframe
    :src="player"
    :style="{height: height+`px`}"
    allowfullscreen>
  </iframe>
</template>

<script>
export default {
  name: "TwitchComponent",
  props:{
    streamer:{
      type:String,
      default: 'neecist'
    },
    height:{
      type:Number,
      default: 350
    },
  },
  data(){
    return{
      player:'https://player.twitch.tv/?channel=' + this.streamer + '&parent=neecist.org'
    }
  }
}
</script>

<style scoped>
iframe{
  width: 95%;
}
</style>
