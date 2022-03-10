<template>
  <div class="home-app">
    <div class="carousel">
      <Carousel :settings="settings" :breakpoints="breakpoints"/>
    </div>
  </div>
  <div class="NEEC-talks">
    <div class="row">
      <div class="col-50">
        <img id="NEECtalksLOGO" src="../assets/Logos/NEECtalks.png">
      </div>
      <div class="col-50">
        <iframe id="NEECtalksPlayer" :src="episode" allowfullscreen="" allow="autoplay; clipboard-write; encrypted-media; fullscreen; picture-in-picture" frameBorder="0"></iframe>
      </div>
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
        },
        episode2:"https://open.spotify.com/embed/episode/6m0bfUJ8qC5qE968BzC8G7?utm_source=generator",
        episode1:"https://open.spotify.com/embed/episode/4521myIGDo3tCxexZgt74r?utm_source=generator",
        episode:null
    };
  },
  methods: {
    randomizeEpisode: function () {
      var random=Math.ceil(Math.random()*2)
      if (random===1)
        this.episode=this.episode1;
      else
        this.episode=this.episode2
    }
  },
  mounted: function(){
    this.randomizeEpisode() 
  }
};
</script>

<style>
.home-app{
    padding-top: 100px;
    background-color:white;
    position: relative;
}
.row {
  display: flex;
  align-items: center;
  justify-content: center;
}
.NEEC-talks {
  background-image: url(../assets/brickWall.png);
  background-size: cover;
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
#NEECtalksPlayer{
  border-radius:12px;
  width:75%;
  height:232px;
}
#NEECtalksLOGO{
  width:70%;
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