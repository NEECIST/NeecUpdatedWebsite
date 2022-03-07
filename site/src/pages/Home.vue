<template>
  <div class="home-app">
    <div class="carousel">
      <Carousel :settings="settings" :breakpoints="breakpoints"/>
    </div>
  </div>
</template>

<script>
import Carousel from '../components/Carousel'

export default {
  name: "home-page",
  components: {
    Carousel,
  },
  data() {
    return {
      settings:{
            itemsToShow:1,
            itemsToScroll:1,
            wrapAround:true,
            snapAlign:'center',
            transition:300,
            autoplay:2000,
            breakpoints:null,
            modelValue:0,
            mouseDrag:true,
            touchDrag:true,
            pauseAutoplayOnHover:true,
        },
        breakpoints: {
            // 700px and up
            700: {
                itemsToShow: 3.5,
                snapAlign: 'center',
            },
            // 1024 and up
            1024: {
                itemsToShow: 5,
                snapAlign: 'start',
            },
        }
    };
  }
};
</script>

<style>
.home-app{
    padding-top: 100px;
    height: 300px;
    background-color:white;
    position: relative;
}
.carousel{
    background-color:white;
    width:98%;
    justify-content: center;
    align-items: center;
    margin-left: 10px;
    margin-right: 10px;
    /*#009DE0*/
}
</style>