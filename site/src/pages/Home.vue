<template>
  <div class="home-app">
    <div class="carousel">
      <Carousel :settings="settings" :breakpoints="breakpoints" :payload="payload"/>
    </div>
  </div>
  <div class="NEEC-talks">
    <div class="talksrow">
      <div class="col-50">
        <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
          <img id="NEECtalksLOGO" src="../assets/Logos/NEECtalks.png">
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
        <div id="NEECtalksLatest">latest episode</div>
      </div>
      <div class="col-50">
        <iframe id="NEECtalksPlayer" :src="episode" allowfullscreen="" allow="autoplay; clipboard-write; encrypted-media; fullscreen; picture-in-picture" frameBorder="0"></iframe>
      </div>
    </div>
  </div>
  <div class="activities-container" :style="{'background-image': `url(${require('../assets/' + activities_image)})`}">
    <div class="activities-column" @mouseover="updateActivities(0)" :class="{'activities-column active': hovering===0}">
      <div class="activities-content">
        <a href="https://drive.google.com/drive/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz" target="_blank">
          <h1>Drive</h1>
          <div class="box">
            <h2>NEEC Drive</h2>
            <p>Acesso a todos os recursos necessários para conseguires trabalhar nas tuas cadeiras!
              Aulas, problemas, testes e exames, tanto de licenciatura como de mestrado. 
              Também podes contribuir com material teu!
            </p>
          </div>
        </a>
      </div>
    </div>
    <div class="activities-column" @mouseover="updateActivities(1)" :class="{'activities-column active': hovering===1}">
      <div class="activities-content">
        <a href="https://drive.google.com/drive/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz" target="_blank">
          <h1>ISTSI</h1>
          <div class="box">
            <h2>ISTSI</h2>
            <p>Queres experienciar o mundo de trabalho? Entra em contacto e candidata-te
              para estagiar no verão em empresas ligadas a todos os ramos de engenharia, para poderes enriquecer
              a tua experiência profissional. 
            </p>
          </div>
        </a>
      </div>
    </div>
    <div class="activities-column" @mouseover="updateActivities(2)" :class="{'activities-column active': hovering===2}">
      <div class="activities-content">
        <a href="https://drive.google.com/drive/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz" target="_blank">
          <h1>Projetos</h1>
          <div class="box">
            <h2>Workshops</h2>
            <p> Queres por em prática alguns dos conhecimentos das aulas? O NEEC ajuda. Inspira-te em alguns dos nossos
              projetos internos ou inscreve-te nos nossos workshops!
            </p>
          </div>
        </a>
      </div>
    </div>
    <div class="activities-column" @mouseover="updateActivities(3)" :class="{'activities-column active': hovering===3}">
      <div class="activities-content">
        <a href="https://drive.google.com/drive/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz" target="_blank">
          <h1>Join Us!</h1>
          <div class="box">
            <h2>Torna-te um NEECo!</h2>
            <p> As inscrições abrem brevemente. Não percas esta oportunidade!
            </p>
          </div>
      </a>
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
      hovering:-1,
      activities_image:'Activities/WhitePane.jpg',
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
        episode:"https://open.spotify.com/embed/episode/0jmTSMg4x1USWTEZ70xSXD?utm_source=generator",
        payload:[
            {main_text: "StartUp the engine!",mainfont:"System-ui", maincolor: 'Snow', mainfontSize: 35, mainleftmargin: 75,mainbottommargin: -170,local:true,image: 'Events/NEECathon.png', page_url: null},
            {local:true,image: 'Events/discord_invite.png', page_url: 'https://discord.gg/kBMRWgZn'},
            //{local:true,image: 'Events/newsletter.png'},
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
    },
    updateActivities: function(entry){
      this.hovering=entry;
      if(entry===0){
        this.activities_image='Activities/Drive.png';
      }else if(entry===1){
        this.activities_image='Activities/ISTSI.jpg';
      }else if(entry===2){
        this.activities_image='Activities/projects.jpg';
      }else if(entry===3){
        this.activities_image='NEECteam.png';
      }
    }
  },
  mounted: function(){
    //this.randomizeEpisode() 
  }
};
</script>

<style>
.home-app{
    padding-top: 100px;
    background-color:white;
    position: relative;
}
@font-face {
  font-family: "Vibur";
  src: local("Vibur"),
   url(../assets/fonts/Vibur/Vibur-Regular.ttf) format("truetype");
}
.activities-container{
  width:100%;
  height: 75vh;
  overflow:hidden;
  background-size: cover;
  background-attachment: fixed;
  background-position: center;
  transition: 0.5s;
}
.activities-container .activities-column{
  width:25%;
  height: 100%;
  float:left;
  border-right: 2px solid rgba(0, 0, 0, 0.5);
  box-sizing: border-box;
  z-index: 1;
}
.activities-container .activities-column:last-child{
  border-right: none;
}
.activities-container .activities-column .activities-content{
  position: relative;
  height: 50%;
}
.activities-container .activities-column .activities-content h1{
  position: absolute;
  top: 50%;
  transform: translateY(-20%);
  background: rgba(0, 0, 0, 0.1);
  width: 100%;
  display: flex;
  justify-content: center;
  align-items: center;
  color: rgba(173, 173, 173, 0.4);
  font-size: 4em;
  border-top: 2px solid rgba(0, 0, 0, 0.5);
  border-bottom: 2px solid rgba(0, 0, 0, 0.5);
  height:276px;
  /*margin-block-start: 0.67em;
  margin-block-end: 0.67em;*/
}
.activities-container .activities-column .activities-content .box{
  width: 100%;
  height: 111%;
  position: absolute;
  top: 95%;
  transform: translateY(100%);
  box-sizing: border-box;
  padding:40px;
  background: rgba(200, 200, 200,1);
  transition: 0.5s;
  margin:0;
  padding:0;
  opacity: 0;
}
.activities-container .activities-column.active .activities-content .box{
  opacity: 0.95;
  transform: translateY(-50%);
  background-color: snow;
}
.activities-container .activities-column .activities-content .box h2{
  margin:0;
  padding:0;
  font-size: 30px;
  color: #262626;
}
.activities-container .activities-column .activities-content .box p{
  font-size: 18px;
  color: #262626;
}
.activities-container .activities-column.active .bg{
  position: absolute;
  top:0;
  left:0;
  width: 100%;
  height: 100%;
  pointer-events: none;
  z-index: -1;
}
.talksrow {
  display: flex;
  align-items: center;
  justify-content: center;
  height: 350px;
}
.row {
  display: flex;
  align-items: center;
  justify-content: center;
  height: 150px;
}
.NEEC-talks {
  background-image: url(../assets/brickWall.png);
  background-size: cover;
  margin-bottom: 1vh;
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
  width:95%;
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
#NEECtalksLatest{
  animation: flickerLatest 1.5s infinite alternate;
  text-align:center;
  align-items:center;
  flex-direction:row;
  display:flex;
  justify-content:center;
  font-size: 100px;
  color:#009DE0;
  font-family: "Vibur", cursive;
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
@keyframes flickerLatest {
  0%, 18%, 22%, 25%, 53%, 57%, 100% {
    text-shadow:
      0 0 4px #7cfbff,
      0 0 11px #7cfbff,
      0 0 19px #7cfbff,
      0 0 40px #64e8ff,
      0 0 80px #64e8ff,
      0 0 90px #64e8ff,
      0 0 100px #64e8ff,
      0 0 150px #64e8ff;
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
}
</style>