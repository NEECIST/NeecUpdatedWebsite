<template>
  <div class="home-app">
    <div class="carousel">
      <Carousel :settings="settings" :breakpoints="breakpoints"/>
    </div>
  </div>
  <div class="NEEC-talks">
    <ul>
      <li>
        <img id="NEECtalksLOGO" src="https://us.123rf.com/450wm/tupungato/tupungato1611/tupungato161100074/66488989-science-doodle-background-seamless-vector-texture-with-physics-concepts-.jpg?ver=6">
      </li>
      <li>
        <iframe src="https://open.spotify.com/embed/show/1cIa5h27pb8ghnfDB7N8Mu?utm_source=generator" allowfullscreen="" allow="autoplay; clipboard-write; encrypted-media; fullscreen; picture-in-picture" frameBorder="0"></iframe>
      </li>
    </ul>
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
.NEEC-talks li{
  display: inline;
  white-space: nowrap
}
.NEEC-talks iframe{
  border-radius:12px;
  width:75%;
  height:232px;
}
#NEECtalksLOGO{
  width:10px;
  height:200px;
  text-align:center;
  align-items:center;
  flex-direction:row;
  display:flex;
  justify-content:left;
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