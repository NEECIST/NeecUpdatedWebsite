<template>
  <div class="home-app">
    <div class="carousel">
      <Carousel :settings="settings" :breakpoints="breakpoints" :payload="payload"/>
    </div>
  </div>
  <div class="NEEC-talks">
    <div class="row">
      <div class="col-50">
        <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
          <img id="NEECtalksLOGO" src="../assets/Logos/NEECtalksBIG.png">
        </a>
      </div>
      <!--<div class="col-33" id="NEECtalksLinks">
        <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
          <div id="NEECtalksSpotify">Spotify</div>
        </a>
        <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
          <div id="NEECtalksYoutube">Youtube</div>
        </a>
      </div>-->
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
            autoplay:3000,
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
        episode:null,
        payload:[
            {main_text: "StartUp the engine!",mainfont:"System-ui", maincolor: 'Snow', mainfontSize: 35, mainleftmargin: 75,mainbottommargin: -170,local:true,image: 'Events/NEECathon.png', page_url: null},
            {local:true,image: 'Events/discord_invite.png', page_url: 'https://discord.gg/kBMRWgZn'},
        ]
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
  height: 350px;
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
  width:75%;
  text-align:center;
  align-items:center;
  flex-direction:row;
  display:flex;
  justify-content:left;
}
#NEECtalksLinks{
  margin-left: 10vw;
  margin-right: 8vw;
}
#NEECtalksSpotify{
  animation: flickerSpotify 1.5s infinite alternate;
  text-align:center;
  align-items:center;
  flex-direction:row;
  display:flex;
  justify-content:center;
  font-size: 55px;
  margin-bottom: 3.5vw;
  color:#1db954;
}
#NEECtalksYoutube{
  animation: flickerYoutube 1.5s infinite alternate;
  text-align:center;
  align-items:center;
  flex-direction:row;
  display:flex;
  justify-content:center;
  font-size: 55px;
  margin-top: 3.5vw;
  color:#ff0000;
}
@keyframes flickerSpotify {
  0%, 18%, 22%, 25%, 53%, 57%, 100% {
    text-shadow:
      0 0 4px rgb(125, 255, 212),
      0 0 11px rgb(125, 255, 212),
      0 0 19px rgb(125, 255, 212),
      0 0 40px #1db954,
      0 0 80px #1db954,
      0 0 90px #1db954,
      0 0 100px #1db954,
      0 0 150px #1db954;
  }
  20%, 24%, 55% {       
    text-shadow: none;
  }
}
@keyframes flickerYoutube {
  0%, 18%, 22%, 25%, 53%, 57%, 100% {
    text-shadow:
      0 0 4px #ff846e,
      0 0 11px #ff846e,
      0 0 19px #ff846e,
      0 0 40px #ff0000,
      0 0 80px #ff0000,
      0 0 90px #ff0000,
      0 0 100px #ff0000,
      0 0 150px #ff0000;
  }
  20%, 24%, 55% {       
    text-shadow: none;
  }
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