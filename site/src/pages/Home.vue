<template>
  <div class="home-app">
    <div class="carousel">
      <Carousel :settings="settings" :breakpoints="breakpoints"/>
    </div>
  </div>
    <div class="container"  :style="{padding: '10px', paddingBottom: '200px'}">
        <div class="activities-row" >
            <div class="col iconss" data-aos="fade-right">
                <i class="fa-solid fa-people-group fa-10x icon"  :style="{float: 'right', paddingRight: '100px'}"></i>
            </div>
            <div class="vl"></div>
            <div class="col" data-aos="fade-left">
                <div class="algo-card">
                    <h2>Quem somos?</h2>
                    <p>O Núcleo de Estudantes de Electrotecnia e Computadores é uma associação sem fins lucrativos que reúne os estudantes de LEEC e MEEC do IST.
                     Somos formados por alunos que, através do seu trabalho voluntário e motivados pela tecnologia e associativismo, 
                    procuram trazer novas ideias, projetos e iniciativas contribuindo para o desenvolvimento de todos os alunos.</p>
                </div>
            </div>
        </div>
        <div class="activities-row" >
            <div class="col" data-aos="fade-right">
                <div class="algo-card" :style="{float: 'right'}" >
                    <h2>Workshops</h2>
                    <p>Queres por em prática alguns dos conhecimentos das aulas? O NEEC ajuda-te. Realizamos workshops de Eletrónica, Soldadura, Programação, Soft-Skills entre muitos outros... </p> 
                    <p><a class = "address-text" href="https://linktr.ee/neecist"><i class="fa-solid fa-gear fa-xl"  :style="{paddingRight: '4px'}"></i>Inscreve-te!</a></p>
                </div>
            </div>
            <div class="vl"></div>
            <div class="col iconss" data-aos="fade-left">
                <i class="fa-solid fa-gear fa-10x icon"  :style="{float: 'left', paddingLeft: '100px'}"></i>
            </div>
        </div>
        <div class="activities-row">
            <div class="col iconss" data-aos="fade-right">
                <i class="fa-solid fa-folder-open fa-10x icon"  :style="{float: 'right', paddingRight: '100px'}"></i>
            </div>
            <div class="vl"></div>
            <div class="col" data-aos="fade-left">
                <div class="algo-card" :style="{float: 'left'}" :data-aos="fade-left" >
                    <h2>Drive MEEC</h2>
                    <p>Acesso a todos os recursos necessários para conseguires trabalhar nas tuas cadeiras! Aulas, problemas,
                     testes e exames, tanto de licenciatura como de mestrado. Também podes contribuir com material teu!</p>
                    <p><a class = "address-text" href="https://drive.google.com/drive/u/3/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz"><i class="fa-solid fa-folder-open fa-xl"  :style="{paddingRight: '4px'}"></i>drive.neecist.org</a></p>
                </div>
            </div>
        </div>
        <div class="activities-row">
            <div class="col" data-aos="fade-right">
                <div class="algo-card" :style="{float: 'right'}">
                    <h2>IST SI</h2>
                    <p>Queres experienciar o mundo de trabalho? Entra em contacto e candidata-te para estagiar no verão em empresas 
                    ligadas a todos os ramos de engenharia, para poderes enriquecer a tua experiência profissional.</p>
                    <p><a class = "address-text" href="https://ist-csm.symplicity.com/students/app/home"><i class="fa-solid fa-id-badge fa-xl"  :style="{paddingRight: '4px'}"></i>Explora!</a></p>
                </div>
            </div>
            <div class="vl"></div>
            <div class="col iconss" data-aos="fade-left">
                <i class="fa-solid fa-id-badge fa-10x icon"  :style="{float: 'left', paddingLeft: '100px'}"></i>
            </div>
        </div>
         <div class="activities-row">
            <div class="col iconss" data-aos="fade-right">
                <i class="fa-solid fa-microchip fa-10x icon"  :style="{float: 'right', paddingRight: '100px'}"></i>
            </div>
            <div class="vl"></div>
            <div class="col" data-aos="fade-left">
                <div class="algo-card">
                    <h2>NEECLab</h2>
                    <p>Precisas de ajuda para desenvolver o teu projeto pessoal? O NEECLab é um laboratório de eletrónica 
                    com as ferramentas necessárias e uma equipa pronta a ajudar-te a transformares a tua ideia num sucesso!</p>
                </div>
            </div>
        </div>
        <div class="activities-row">
            <div class="col" data-aos="fade-right">
                <div class="algo-card" :style="{float: 'right'}">
                    <h2>NEECTalks</h2>
                    <p>NEECTalks é um podcast onde discutimos projectos, tecnologia e trazemos convidados experientes de diversos contextos
                     que envolvem a nossa área no formato de uma conversa informal.
                        Se és curioso e tens vontade de aprender, junta-te a nós!</p>
                        <a class = "address-text" href="https://www.youtube.com/user/NEECIST" target="_blank">
                        <i class="fa-brands fa-youtube fa-2x" :style="{ padding: '4px'}"></i>
                        </a>
                        <a class = "address-text" href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank"><i class="fa-brands fa-spotify fa-2x" :style="{ padding: '4px'}"></i></a>
                </div>
            </div>
            <div class="vl"></div>
            <div class="col " data-aos="fade-left">
                <div class="col-50" :style="{width: '60%', float: 'left'}">
                    <iframe id="NEECtalksPlayer" :src="episode" allowfullscreen="" allow="autoplay; clipboard-write; encrypted-media; fullscreen; picture-in-picture" frameBorder="0"></iframe>
                </div> 
            </div>
        </div>
    </div>
 
</template>

<script>
import Carousel from '../components/Carousel'
import arduino from "../assets/Activities/Arduino.png"
import GoogleDrive from "../assets/Activities/GoogleDrive.png"
import ISTSI from "../assets/Activities/ISTSI.png"
import NEEC_Logo from "../assets/Logos/NEEC_Logo.png"

export default {
  name: "home-page",
  components: {
    Carousel,
  },
  data() {
    return {
      hovering:-1,
      activities_image:'Activities/WhitePane.jpg',
      aboutList: [
                    {
                        name: "Quem somos?",
                        content: "O NEECIST - núcleo de Estudantes de Electrotecnia e Computadores - é uma associação sem fins lucrativos que reúne os estudantes de LEEC e MEEC do IST. Somos formados por alunos que, através do seu trabalho voluntário e motivados pela tecnologia e associativismo, procuram trazer novas ideias, projetos e iniciativas contribuindo para o desenvolvimnentos de todos os alunos."
                    },
                    {
                        name: "O que fazemos?",
                        content: "Procuramos ajudar os alunos a intregarem-se no mercado de trabalho e dar formação extra-curricular. Organizamos workshops, estágios de verão, uma hackathon e até um podcast! Tentamos proporcionar aos alunos de LEEC e de MEEC conteúdo e oportunidades para se desenvolverem a nível académico e profissional. "
                    },
                    {
                        name: "Desde quando?",
                        content: "O NEECIST foi fundado no dia 19 de setembro de 2003, como uma associação que representasse os alunos de LEEC. A jovem associação como objetivo a união e representação dos alunos, recorrendo à organização de atividades de caráter social e profissional. Hoje, tal como no início, estes objetivos mantém-se, em conjunto com muitos outros que procuram trazer mais oportunidades aos alunos de LEEC e MEEC."
                    }
                ],
      drive:{
        image: GoogleDrive,
        link: "https://drive.google.com/drive/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz",
        link_message: "Aceder",
        main_color: "#1FA463",
        secondary_color: "#FFD04B",
        top: 55,
        left: 50,
        zoom_height: 350,
        zoom_position: 85,
        title: "NEEC Drive",
        description: "Acesso a todos os recursos necessários para conseguires trabalhar nas tuas cadeiras! Aulas, problemas, testes e exames, tanto de licenciatura como de mestrado. Também podes contribuir com material teu!",
        left_padding: 0,
        right_padding: 240,
        top_flatted_screen: 114,
      },
      arduino:{
        image: arduino,
        redirect_function: 'Projects',
        link_message: "Visitar",
        main_color: "#D0F2F2",
        secondary_color: "#00979C",
        top: 50,
        left: 50,
        image_height: 250,
        zoom_height: 235,
        zoom_position: 85,
        title: "Projetos",
        description: "Queres por em prática alguns dos conhecimentos das aulas? O NEEC ajuda. Inspira-te em alguns dos nossos projetos internos ou inscreve-te nos nossos workshops!",
        left_padding: 0,
        right_padding: 250,
        top_flatted_screen: 116,
      },
      ISTSI:{
        image: ISTSI,
        main_color: "#7c587f",
        secondary_color: "#a4bcbc",
        title: "ISTSI",
        description: "Queres experienciar o mundo de trabalho? Entra em contacto e candidata-te para estagiar no verão em empresas ligadas a todos os ramos de engenharia, para poderes enriquecer a tua experiência profissional.",
        left_padding: 0,
        right_padding: 225,
        zoom_height: 400,
        zoom_position: 85,
        top_flatted_screen: 120,
      },
      recrutamento:{
        image: NEEC_Logo,
        link: "mailto:contemcomigo@neecist.org",
        link_message: "Candidatar",
        main_color: "#F0FFF0",
        secondary_color: "#C0C0C0", //#009DE0
        zoom_height: 325,
        zoom_position: 85,
        title: "Recrutamento",
        description: "O NEEC está a recrutar! Se queres pertencer ao nosso núcleo, envia a tua carta de motivação! As inscrições fecham à meia noite de domingo, 10/04.",
        left_padding: 0,
        right_padding: 250,
        top_flatted_screen: 115
      },
      settings:{
            itemsToShow:1,
            itemsToScroll:1,
            wrapAround:true,
            snapAlign:'center',
            transition:300,
            autoplay:10000,
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
        episode:"https://open.spotify.com/embed/episode/7FcE8aZsuVhZNUAOp8HX9M?utm_source=generator&theme=0",
        
    };
  },
  methods: {
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
    },
    redirect(page) {
      this.show_menu = false;
      this.$router.push({ name: page });
    }
  }
};
</script>

<style>
.home-app{
    padding-top: 60px;
    background-color:white;
    position: relative;
}
@font-face {
  font-family: "Vibur";
  src: local("Vibur"),
   url(../assets/fonts/Vibur/Vibur-Regular.ttf) format("truetype");
}
.address-text{
    color: #303633;
}
.address-text:hover{
    color: #009DE0;
}

.about-container {
    padding: 10px;
    background-color:red;
}
.algo-card{
    width: 50%;
    padding-left: 100px;
    padding-right: 100px;
}
.icon{
    color:#303633;
}
.icon:hover{
    color:#009DE0;
}
.algo-card p{
    font-size: 20px;
}

.vl {
  border-left: 4px solid #DCDCDC;
  height: 100%;
  border-radius: 8px;
}
.col {
  width: 50%;
  display: inline-block;
}
.about-card {
    display: inline-block;
    background-color:cyan;
    border-radius: 4px;
    width: 25%;
    height: 100%;
    margin: 10px;
}

.card-title{
    background-color:yellow;
    height: 25%;
}
.card-content{
background-color:white;
padding-left:10px;
padding-right:10px;
}

.activities-board{
    margin-top: 60px;
    padding: 40px;
}

.activities-board .card-row{
  display: flex;
  flex-wrap: wrap;
  justify-content: space-around;
  margin:auto;
}

.activities-board .card-row .card{
  flex: 1;
}

.activities-board .card-row .single-card{
  flex: 0;
}

.activities-board .card-row .card:first-child {
  margin-right: 0px;
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
.activities-row {
  display: flex;
  align-items: center;
  justify-content: center;
  height: 300px;
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
    width:100%;
    justify-content: center;
    align-items: center;
}
@media(max-width: 1200px)
{
  .activities-board .card-row .card{
    flex: 0;
  }
}
@media(max-width: 990px)
{
  .activities-board{
    padding-top: 5px;
    padding-bottom: 210px;
  }
}

</style>
