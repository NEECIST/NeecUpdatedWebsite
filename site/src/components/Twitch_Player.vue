<template>
  <iframe
    src="https://player.twitch.tv/?channel=fruity&parent=neecist.org"
    :style="{height: height+`px`}"
    allowfullscreen>
  </iframe>
</template>

<script>
export default {
  name: "TwitchComponent",
  props:{
    height:{
      type:Number,
      default: 350
    },
  }
}
</script>

<style scoped>
iframe{
  width: 95%;
}
</style>