<template>
    <div class="oportunities-app">

       <div class="description-projects">
           <div class="projects-text">
                <div class="description-title">
                    Projetos
                </div>
                <div class="description-text">Conhece todos os projetos que o NEEC está a desenvolver!
                </div>
            </div>
            <img src="../assets/computer.png"/>
        </div>

        <div class="team">
             <ul v-if="cardList && cardList.length" style="list-style: none;display: flex; flex-direction: row; flex-wrap: wrap;">
                <li v-for="(card,card_id) in cardList" :key="card_id" style=" flex: 0 1 50%;padding-bottom: 10px;">
                    <div class="card" >
                        <img v-if="card.image" :src="card.image"/>
                        <h2>{{card.name}}</h2>
                        <h4 v-if="card.subtitle">{{card.subtitle}}</h4>
                        <p><span v-html="card.desc"/></p>
                    </div>
                </li>
            </ul>
        </div>
    </div>
</template>

<script>
import NEECTALKS from "../assets/Logos/NEECtalks.png"
import NEECTVBGone from "../assets/Projects/tvbg.jpeg"
import NEECPov from "../assets/Projects/pov.jpg"
import NEEConsola from "../assets/Projects/NEEConsola.png"
import NEECduino from "../assets/Projects/neecduino.png"
import blinker from "../assets/Projects/blinker.jpg"
import NEECathon from "../assets/Projects/neecathon_pug.png"
import NEECReact from "../assets/Projects/NEECReact.jpg"
import NEECuick from "../assets/Projects/NEECuick.jpg"
import chaves from "../assets/Projects/chaves.jpg"
import tiro from "../assets/Projects/tiro.jpg"
import BanaNEEC from "../assets/Projects/BanaNEEC.jpg"
import levitaNEEC from "../assets/Projects/levitaNEEC.jpg"
import NEECSimon from "../assets/Projects/NEECSimon.jpg"

export default {
  name: "projects-page",
  data() {
      return {
        cardList: [
            {name:'NEECathon',subtitle:"Uma Hackathon sem barreiras",desc:'Evento anual onde se simula uma componente de startup durante uma Hackaton de 48 horas.\n Para participar, só é necessário uma ideia.\nO NEEC trata do resto. Terás acesso a todos os componentes, todos o material necessário, apoio constante, impressoras 3D e comida à pala no local do evento.', image:NEECathon},
            {name:'NEECTalks',subtitle:"Conversas sobre engenharia",desc:'Podcast onde discutimos projetos e tecnologia com convidados de renome de diversos contextos que envolvem a nossa área.\nSe és curioso e tens vontade de aprender, junta-te à conversa!\n\nSpotify: https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu\nYoutube: https://www.youtube.com/user/NEECIST/videos', image:NEECTALKS},
            {name:'NEECReact',subtitle:'Um jogo de reação a dois',desc:'Junta-te a um amigo e confirma de uma vez por todas quem é o mais rápido!\n Usando apenas um neecduino, uma breadboard, resistências e LEDs, os jogadores têm que retirar as 3 vidas do adversário dependendo do comando gerado pelo LED central.', image:NEECReact},
            {name:'NEECuick',subtitle:'Um jogo de memória e reação viciante',desc:'Se queres o jogo mais desafiante do NEEC, não procures mais.\n⚠️Necessário: Reação,Concentração,Memorização⚠️\n\n Um jogo criado somente com um neecduino,breadboard, LEDs e condensadores. É necessário clicar no botão correto consoante o LED que se acende, antes que o contador chegue a zero.', image:NEECuick},
            {name:'NEEConsola',subtitle:'(Em desenvolvimento)',desc:'', image:NEEConsola},
            {name:'LevitaNEEC',subtitle:'(Em desenvolvimento)',desc:'Consiste na construção de uma plataforma levitadora que é controlada através de campos eletromagnéticos criados por ímans e bobinas da base.\nTambém tem uma componente de IoT em que pretendemos mostrar valores lidos por sensores de hall utilizados para ajustar o controlador da plataforma levitadora e talvez controlar os movimentos da própria plataforma através de uma aplicação móvel.', image:levitaNEEC},
            {name:'Sensor de Chaves',subtitle:null,desc:'Agora é possível saber sempre quando a sede do NEEC está aberta. Se vires um luz verde no estado da sede, alguém estará disponível para te ajudar!', image:chaves},
            {name:'BanaNEEC',subtitle:null,desc:'Um projeto educativo para cultivar o interesse na ciência nos mais novos.\nCom um simples neecduino e um cacho de bananas, é possível fazer um instrumento musical ao alcance de todos.', image:BanaNEEC},
            {name:"Tir'o NEEC",subtitle:'Testa a tua pontaria contra os teus amigos!',desc:'Com o uso de um neecduino, resistências LDR e um laser, criámos um jogo de tiro ao alvo. As pontuações atingidas dentro de um limite de tempo são utilizadas em eventos do NEEC.', image:tiro},
            {name:'NEECduino',subtitle:'Um arduino que podes construir com o apoio do NEEC',desc:'Um dispositivo barato, funcional e fácil de programar, acessível a estudantes e projetistas amadores. Aprende a soldar e a programar um arduino desde raiz, com um apoio pessoal e personalizado atravês dos workshops do NEEC.\n\nA placa é composta por um microcontrolador, circuitos de entrada/saída, podendo ser facilmente conectada a um computador e programada via IDE utilizando uma linguagem baseada em C/C++.', image:NEECduino},
            {name:'Blinker',subtitle:'O teu primeiro contacto com o NEEC',desc:'Um simples circuito eletrónico que pode ser montado em minutos, que podes levar na roupa para representar MEEC!', image:blinker},
            {name:'NEECSimon',subtitle:'Jogo do Simon Says (Em desenvolvimento)',desc:'O famoso jogo agora numa consola portátil!', image:NEECSimon},
            {name:'TVBGone',subtitle:null,desc:'O TV-Bgone é um controlo remoto universal para ligar ou desligar qualquer televisão!\nQuando ligado,começa a percorrer uma sequencia de códigos que controlam a função POWER de vários modelos de televisões. Estes códigos são enviados para os LEDs de Infra-Vermelho ligados à placa.', image:NEECTVBGone},
            {name:'POV',subtitle:null,desc:'Display de LEDs que, piscando a uma frequência elevada, consegue escrever mensagens de luz no ar.', image:NEECPov},
        ]
      }
  },
  methods:{
    curateCardText(List) {
        List.forEach(element => {
            element.desc=this.linkify(element.desc)
        });
    },
    linkify(inputText) {
        //eslint-disable-next-line
        const pattern1 = /(\b(https?|ftp):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/gim;
        let text = inputText.replace(pattern1, '<a href="$1" target="_blank">$1</a>');
        //eslint-disable-next-line
        const pattern2 = /(^|[^\/])(www\.[\S]+(\b|$))/gim;
        text = text.replace(pattern2, '$1<a href="http://$2" target="_blank">$2</a>');
        
        return text;
    }
  },
  mounted(){
    this.curateCardText(this.cardList);
  }
};
</script>

<style scoped>
.description-projects{
    padding-top: 100px;
    height: 300px;
    background-color:white;
    position: relative;
}

.card {
    background: white;
    border-radius: 5px;
    box-shadow: 0 4px 8px 0 rgb(0 0 0 / 20%), 0 6px 20px 0 rgb(0 0 0 / 19%);
    text-align: center;
    padding: 5px;
    margin: 10px;
    white-space: pre-wrap;
    padding-left: 20px;
    padding-right: 20px;
    height: 100%;
    box-sizing: border-box;
}
.card img{
    width:150px;
    height: 150px;
    border-radius:80%;
}
.description-projects img{
    width: 700px;
    /*transform: rotate(30deg);*/
    clip-path: inset(0 5.5em 8em 3em);
    position: absolute;
    top:100px;
    left: -60px;
    z-index: 0;
}
.projects-text{
    float: right;
    padding-right: 40px;
    position: relative;
    z-index: 1;
}
.description-title{
    font-family: 'Raleway', sans-serif;
    font-size: 50px;
    font-weight: bolder;
    color: #505050;
    text-align: right;
    padding-top: 30px;
}
.description-text{
    margin-top: 10px;
    background-color: #009DE0;
    border-radius: 5px;
    font-size: 30px;
    font-family: 'Karla';
    width: 750px;
    padding-right: 40px;
    padding-top: 15px;
    padding-bottom: 15px;
    margin-right: -40px;
    text-align: right;
    color: #ffffff;
    line-height: 50px;
}
.team{
    padding: 15px;
    background-color: #ecf7ff;
}
.team-flex{
    padding-left: 50px;
    padding-right: 50px;
    display: flex;
    flex-wrap: wrap;
    justify-content: space-around;
    margin-right: 8vw;
    margin-left: 8vw;
    margin-top: 30px;
}
.teams_container {
    position: relative;
    height: auto;
    width: auto;
}
.linkedin-icons {
    opacity: 0;
    position:absolute;
    top:-75px;
    left:0px;
    right:85px;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.insta-icons {
    opacity: 0;
    position:absolute;
    top:-75px;
    left:85px;
    right:0;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.git-icons {
    opacity: 0;
    position:absolute;
    top:75px;
    left:85px;
    right:0;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.mail-icons {
    opacity: 0;
    position:absolute;
    top:75px;
    left:-85px;
    right:0;
    bottom:0;
    margin: auto;
    border-radius: 0px;
    width:60px;
    height:60px;
    transition: .5s ease;
}
.teams_container:hover .git-icons,
.teams_container:hover .mail-icons,
.teams_container:hover .insta-icons,
.teams_container:hover .linkedin-icons {
  opacity: 1;
}
.team-member-name {
    display: flex;
    flex-direction: row;
    justify-content: space-around;
}
.team-member {
    transition: .5s ease;
}
.team-member img{ 
    height: 220px;
    width: 220px;
    margin-right: 10px;
    margin-left: 10px;
}
.teams_container:hover .team-member {
  opacity: 0.5;
}
.member-name{
    width: 100px;
    font-size: 22px;
    text-align: center;
    font-family:'Lato', sans-serif;
    color: #262626;
}
.icon-team-member {
    height: 60px;
}
@media screen and (max-width: 1200px) {
    .team-flex {
        padding-left: 12px;
        margin-right: 5vw;
        margin-left: 5vw;
    }
}
@media screen and (max-width: 800px) {
    .description-title{
        font-size: 40px;
    }
    .description-text{
        font-size: 18px;
        width: 320px;
        padding-right: 40px;
        line-height: 28px;
    }
    .description-projects img{
        width: 475px;
        top: 200px;
    }
    
    .team-flex {
        padding-left: 12px;
        margin-right: 5vw;
        margin-left: 5vw;
    }
    .team-flex img{
        height: 140px;
        width: 140px;
        margin-top: 30px;
        flex: 0 0 50%;
        margin-right: 10px;
    }
    .member-name{
        font-size: 17px;
        margin-left:13%;
    }
    .icon-team-member {
        height: 40px !important;
        width: 40px !important;
        margin-top: 20px !important;
        margin-right: 0px !important;
    }
}
@media screen and (max-width: 400px) {
    .description-projects{
        height: 200px;
        background-color:white;
        position: relative;
    }
    .description-title{
        font-size: 30px;
        padding-top: 10px;
    }
    .description-text{
        font-size: 16px;
        width: 250px;
        padding-right: 30px;
        padding-left: 20px;
        line-height: 24px;
    }
    .description-projects img{
        width: 475px;
        top: 150px;
    }
    .team{
        padding-top: 20px;
    }
    
    .team-flex {
        margin-right: 2vw;
        margin-left: 2vw;
    }
    .team-flex img{
        height: 120px;
        width: 120px;
        margin-top: 5px;
        flex: 0 0 50%; margin-right: 10px;
    }
    .member-name{
        margin-left:6%;
    }
}
</style>