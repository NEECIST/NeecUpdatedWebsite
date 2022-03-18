<template>
    <div class="team-app">

       <div class="description-team">
           <div class="team-text">
                <div class="description-title">
                    <abbr title="Núcleo de Estudantes de Eletrotécnia e Computadores">NEEC</abbr> Team
                </div>

                <div class="description-text">Conhece a equipa por trás do projeto que não para de crescer!
                </div>
            </div>
            <img src="../assets/NEECteam.png"/>
        </div>

        <div class="team">
            <div class="team-flex">
                <div v-for="member in team.members" :key="member.name">
                    <div class="teams_container">
                        <div class="team-member">
                            <img :src="member.image">
                        </div> 
                        <div class="linkedin-icons">
                            <a :href="member.linkedin_url" target="_blank">
                                <img class="icon-team-member" :src="linkedin_icon_link"/>
                            </a>
                        </div>
                        <div class="insta-icons">
                            <a :href="member.insta_url" target="_blank">
                                <img class="icon-team-member" :src="insta_icon_link"/>
                            </a>
                        </div>
                        <div class="git-icons">
                            <a :href="member.git_url" target="_blank">
                                <img class="icon-team-member" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/github/github-original.svg"/>
                            </a>
                        </div>
                        <div class="mail-icons">
                            <a :href="member.mail" target="_blank">
                                <img class="icon-team-member" :src="mail_icon_link"/>
                            </a>
                        </div>                                   
                    </div>
                    <div class="team-member-name">
                        <p class="member-name">{{ member.name }}</p>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import linkedin_logo from "../../static/linkedin.svg"
import insta_logo from "../../static/instagram.svg"
import gmail_logo from "../../static/gmail.svg"
import tiago from "../assets/NEEC/Tiago.jpg"
import alexandra from "../assets/NEEC/Alex.jpg"
import midoes from "../assets/NEEC/Midoes.jpg"

export default {
  name: "team-page",
  data() {
      return {
        team: {
            name: "NEEC",
            description: "We are NEEC!",
            members:[
                {name: "André Pereira",mail: 'mailto:andregdpereira@gmail.com',git_url: 'https://github.com/Andre-MR-Pereira',insta_url: 'https://www.instagram.com/andre_periphery/',image: 'https://avatars.githubusercontent.com/u/54562621?v=4', linkedin_url: 'https://www.linkedin.com/in/andr%C3%A9-pereira-680209194/'},
                {name: "Vasco Rodrigues",mail: 'mailto:andregdpereira@gmail.com',git_url: 'https://github.com/VascoDVRodrigues',insta_url: 'https://www.instagram.com/vascovrodrigues/',image: 'https://avatars.githubusercontent.com/u/34923176?v=4', linkedin_url: 'https://www.linkedin.com/in/andr%C3%A9-pereira-680209194/'},
                {name: "António Coimbra",mail: 'mailto:andregdpereira@gmail.com',git_url: 'https://github.com/antoniocoimbraa',insta_url: 'https://www.instagram.com/antoniocoimbraa/',image: 'https://avatars.githubusercontent.com/u/65049521?v=4', linkedin_url: 'https://www.linkedin.com/in/andr%C3%A9-pereira-680209194/'},
                //{name: "Gonçalo Midões",image: 'https://avatars.githubusercontent.com/u/69457730?v=4', linkedin_url: 'https://www.linkedin.com/in/goncalo-midoes/'},
                {name: "Gonçalo Midões",mail: 'mailto:andregdpereira@gmail.com',git_url: 'https://github.com/Midas-sudo',insta_url: 'https://www.instagram.com/goncalopm01/',image: midoes, linkedin_url: 'https://www.linkedin.com/in/goncalo-midoes/'},
                {name: "Tiago Gonçalves",mail: 'mailto:andregdpereira@gmail.com',git_url: 'https://github.com/Varsenaiga',insta_url: 'https://www.instagram.com/tiago.angelico.goncalves/',image: tiago, linkedin_url: 'https://www.linkedin.com/in/tiago-gon%C3%A7alves-b5a87b183/'},
                {name: "Alexandra Fernandes",mail: 'mailto:andregdpereira@gmail.com',git_url: 'https://github.com/AlexaFernandes',insta_url: 'https://www.instagram.com/alex.cookiie/',image: alexandra, linkedin_url: 'https://www.linkedin.com/in/alexandra-fernandes-a6b356136/'},
            ]
        },
        linkedin_icon_link: linkedin_logo,
        insta_icon_link: insta_logo,
        mail_icon_link: gmail_logo,
      }
  }
};
</script>



<style>
.description-team{
    padding-top: 100px;
    height: 300px;
    background-color:white;
    position: relative;
}
.description-team img{
    width: 700px;
    /*transform: rotate(30deg);*/
    clip-path: inset(0 5.5em 11em 3em);
    position: absolute;
    top:100px;
    left: -60px;
    z-index: 0;
}
.team-text{
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
    padding-top: 40px;
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
    .description-team img{
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
    .description-team{
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
    .description-team img{
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