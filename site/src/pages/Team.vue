<template>
  <div class="team-app" :style="{ padding: '10px', paddingTop: '4vw', paddingBottom: '200px', fontFamily: 'Roboto' }">
    <h2>Conhece a nossa equipa!</h2>
    <div class="team">
      <!-- if(initialized) -->
      <div v-if="initialized">
        <div class="team-flex">
          <!-- for board=[Vasco, Monica] -->
          <!-- board.forEach(member => {}) -->
          <div v-for="member in board" :key="member.id" data-aos="zoom-in">
            <div>
              <div :style="{ fontSize: '20px' }">
                <h3 v-if="member.treasurer">Tesoureira</h3>
                <h3 v-if="member.president">Presidente</h3>
              </div>
            </div>
            <div class="teams_container">
              <div class="team-member">
                <img :src="member.url" />
              </div>
            </div>
            <div class="team-member-name">
              <p class="member-name">{{ member.name }}</p>
            </div>
          </div>
        </div>

        <div class="team-flex">
          <!-- for members=[Diogo, Gonçalo, Margarida .....] -->
          <div v-for="member in members" :key="member.id" data-aos="zoom-in">
            <div class="teams_container">
              <div class="team-member">
                <img :src="member.url" />
              </div>
            </div>
            <div class="team-member-name">
              <p class="member-name">{{ member.name }}</p>
            </div>
            <div>
              <p :style="{ fontSize: '30px', marginTop: '0px', paddingTop: '0px' }">
                <a href="#team-explaination"><i v-if="member.team.includes('NEECIT')" class="fa-solid fa-laptop-code team-badge" :style="{ paddingRight: '4px' }"></i></a>
                <a href="#team-explaination"><i v-if="member.team.includes('Design')" class="fa-solid fa-pen team-badge" :style="{ paddingRight: '4px' }"></i></a>
                <a href="#team-explaination"><i v-if="member.team.includes('Divulgacao')" class="fa-solid fa-newspaper team-badge" :style="{ paddingRight: '4px' }"></i></a>
                <a href="#team-explaination"><i v-if="member.team.includes('Multimedia')" class="fa-solid fa-video team-badge" :style="{ paddingRight: '4px' }"></i></a>
              </p>
            </div>
          </div>
        </div>
      </div>

      <!-- else -->
      <div :style="{ display: 'flex', justifyContent: 'center' }" v-else>
        <PulseLoader :color="'#009DE0'"></PulseLoader>
      </div>

      <h2 :style="{ paddingTop: '50px' }">Interessado/a nas funções de cada uma das equipas?</h2>

      <div id="team-explaination" :style="{ paddingLeft: '50px', paddingRight: '50px' }">
        <div class="activities-row" data-aos="zoom-in">
          <div class="col" :style="{ width: '25%', paddingLeft: '24px', paddingRight: '24px', flexDirection: 'column' }">
            <i class="fa-solid fa-laptop-code fa-6x icon"></i>
            <h3>NEECIT</h3>
            <p>
              O NEEC IT é a nossa equipa de desenvolvimento e de manutenção dos serviços do núcleo, como por exemplo a drive, o discord, e este mesmo site. Desenvolvemos também projetos mais pessoais
              que apresentamos na nossa banca em eventos oficiais, tais como o NEECBoto, o LevitaNEEC e o NEECQuick.
            </p>
          </div>
          <div class="vl"></div>
          <div class="col" :style="{ width: '25%', paddingLeft: '24px', paddingRight: '24px', flexDirection: 'column' }">
            <i class="fa-solid fa-pen fa-6x icon"></i>
            <h3>Design</h3>
            <p>Design é a equipa que trata da imagem do núcleo. Utiliza ferramentas como Adobe Illustrator e Canva para fazer os nossos posts, stickers, flyers, posters, e muito mais.</p>
          </div>
          <div class="vl"></div>
          <div class="col" :style="{ width: '25%', paddingLeft: '24px', paddingRight: '24px', flexDirection: 'column' }">
            <i class="fa-solid fa-video fa-6x icon"></i>
            <h3>Multimédia</h3>
            <p>
              Muito como o Design, Multimédia também lida com o conteúdo que lançamos ao público mas mais focado em conteúdo vídeo. Esta é a equipa que trata dos nossos vídeos, recaps de eventos, e
              que organiza o nosso podcast - as NEECTalks!
            </p>
          </div>
          <div class="vl"></div>
          <div class="col" :style="{ width: '25%', paddingLeft: '24px', paddingRight: '24px', flexDirection: 'column' }">
            <i class="fa-solid fa-newspaper fa-6x icon"></i>
            <h3>Divulgação</h3>
            <p>
              A equipa de Divulgação é a equipa que gere as nossas redes sociais e caixa de entrada. É a equipa que contacta com o exterior e que trabalha para trazer oportunidades de estágios,
              bolsas, eventos, e tudo o que seja do interesse dos alunos do nosso curso.
            </p>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import "vue3-carousel/dist/carousel.css";
import axios from "axios";
import PulseLoader from "vue-spinner/src/PulseLoader.vue";
export default {
  name: "team-page",
  data() {
    return {
      initialized: false,
      members: [],
      board: [],
      teamsData: [
        {
          title: "Design",
          desc: "Design é a equipa que trata da imagem do núcleo. Utiliza ferramentas como Adobe Illustrator e Canva para fazer os nossos posts, stickers, flyers, posters, e muito mais.",
        },
        {
          title: "NEECIT",
          desc: "O NEEC IT é a nossa equipa de desenvolvimento e de manutenção dos serviços do núcleo, como por exemplo a drive, o discord, e este mesmo site. Desenvolvemos também projetos mais pessoais que apresentamos na nossa banca em eventos oficiais, tais como o NEECBoto, o LevitaNEEC e o NEECQuick.",
        },
        {
          title: "Multimédia",
          desc: "Muito como o Design, Multimédia também lida com o conteúdo que lançamos ao público mas mais focado em conteúdo vídeo. Esta é a equipa que trata dos nossos vídeos, recaps de eventos, e que organiza o nosso podcast - as NEECTalks!",
        },
        {
          title: "Divulgação",
          desc: "A equipa de Divulgação é a equipa que gere as nossas redes sociais e caixa de entrada. É a equipa que contacta com o exterior e que trabalha para trazer oportunidades de estágios, bolsas, eventos, e tudo o que seja do interesse dos alunos do nosso curso.",
        },
      ],
    };
  },
  created() {
    const config = {
      headers: {
        Authorization: `Bearer 6d91366b1570f57e18431d3581ed78afe6bb64d7fde38be4b3df3f08fd4b8d83184344a85b0a49925c3a957d58e9764d8ae4bdc2fcdc5952fea7948ba3eaf724488648a354dfd7ab6abf1c1357ece89dce648554c33169c705e5e0d4da2363cb2b7ebde31dc9b8e2a24c61810f109a57c0b59415e5ddb95ee2ee568475c5abd8`,
      },
    };

    axios
      .get("https://api.neecist.org/api/membros?populate=Foto&filters[active][$eq]=true", config)
      .then((response) => {
        console.log(response.data);
        response.data.data.forEach((element) => {
          const attributes = element.attributes;
          const imgUrl = "https://api.neec.midas-cloud.xyz" + attributes.Foto.data.attributes.url;
          if (attributes.Presidente || attributes.Tesoureiro) {
            this.board.push({ id: element.id, name: attributes.frstlstName, url: imgUrl, president: attributes.Presidente, treasurer: attributes.Tesoureiro });
          } else {
            this.members.push({ id: element.id, name: attributes.frstlstName, url: imgUrl, team: attributes.Equipas });
          }
        });
      })
      .finally(() => {
        this.initialized = true;
      });
  },
  components: { PulseLoader },
};
</script>

<style>
.hl {
  border: 3px solid #dcdcdc;
  width: 100%;
  height: 0px;
  border-radius: 4px;
}
.team-item-title {
  background-color: #009de0;
  min-height: 100px;
  font-size: 20px;
  border-radius: 8px;
  display: flex;
  justify-content: center;
  align-items: center;
}
.vl {
  border-left: 4px solid #dcdcdc;
  height: 100%;
  border-radius: 8px;
}
.team-item-desc {
  background-color: #505050;
  min-height: 400px;
  font-size: 20px;
  border-radius: 8px;
  display: flex;
  justify-content: center;
  align-items: center;
}
#team-explaination {
  padding-bottom: 2vh;
}
.team-badge {
  color: #303633;
}
.team-badge:hover {
  color: #009de0;
}
.description-team {
  padding-top: 100px;
  height: 300px;
  background-color: white;
  position: relative;
}
.description-team img {
  width: 700px;
  /*transform: rotate(30deg);*/
  clip-path: inset(0 5.5em 11em 3em);
  position: absolute;
  top: 100px;
  left: -60px;
  z-index: 0;
}
.team-text {
  float: right;
  padding-right: 40px;
  position: relative;
  z-index: 1;
}
.description-title {
  font-size: 50px;
  font-weight: bolder;
  color: #505050;
  text-align: right;
  padding-top: 30px;
}
.description-text {
  margin-top: 10px;
  background-color: #009de0;
  border-radius: 5px;
  font-size: 30px;
  width: 750px;
  padding-right: 40px;
  padding-top: 15px;
  padding-bottom: 15px;
  margin-right: -40px;
  text-align: right;
  color: #ffffff;
  line-height: 50px;
}
.team {
  padding-top: 40px;
}
.team-flex {
  padding-left: 50px;
  padding-right: 50px;
  display: flex;
  flex-wrap: wrap;
  justify-content: space-around;
  margin-right: 8vw;
  margin-left: 8vw;
}
.teams_container {
  position: relative;
  height: auto;
  width: auto;
}
.linkedin-icons {
  opacity: 0;
  position: absolute;
  top: -75px;
  left: 0px;
  right: 85px;
  bottom: 0;
  margin: auto;
  border-radius: 0px;
  width: 60px;
  height: 60px;
  transition: 0.5s ease;
}
.insta-icons {
  opacity: 0;
  position: absolute;
  top: -75px;
  left: 85px;
  right: 0;
  bottom: 0;
  margin: auto;
  border-radius: 0px;
  width: 60px;
  height: 60px;
  transition: 0.5s ease;
}
.git-icons {
  opacity: 0;
  position: absolute;
  top: 75px;
  left: 85px;
  right: 0;
  bottom: 0;
  margin: auto;
  border-radius: 0px;
  width: 60px;
  height: 60px;
  transition: 0.5s ease;
}
.mail-icons {
  opacity: 0;
  position: absolute;
  top: 75px;
  left: -85px;
  right: 0;
  bottom: 0;
  margin: auto;
  border-radius: 0px;
  width: 60px;
  height: 60px;
  transition: 0.5s ease;
}

.team-member-name {
  display: flex;
  flex-direction: row;
  justify-content: space-around;
}
.team-member {
  transition: 0.5s ease;
}
.team-member img {
  height: 160px;
  margin-right: 10px;
  margin-left: 10px;
}
.teams_container:hover .team-member {
  opacity: 0.5;
}
.member-name {
  width: 100px;
  font-size: 22px;
  text-align: center;
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
  .description-title {
    font-size: 40px;
  }
  .description-text {
    font-size: 18px;
    width: 320px;
    padding-right: 40px;
    line-height: 28px;
  }
  .description-team img {
    width: 475px;
    top: 200px;
  }

  .team-flex {
    padding-left: 12px;
    margin-right: 5vw;
    margin-left: 5vw;
  }
  .team-flex img {
    height: 140px;
    width: 140px;
    margin-top: 30px;
    flex: 0 0 50%;
    margin-right: 10px;
  }
  .member-name {
    font-size: 17px;
    margin-left: 13%;
  }
  .icon-team-member {
    height: 40px !important;
    width: 40px !important;
    margin-top: 20px !important;
    margin-right: 0px !important;
  }
}
@media screen and (max-width: 400px) {
  .description-team {
    height: 200px;
    background-color: white;
    position: relative;
  }
  .description-title {
    font-size: 30px;
    padding-top: 10px;
  }
  .description-text {
    font-size: 16px;
    width: 250px;
    padding-right: 30px;
    padding-left: 20px;
    line-height: 24px;
  }
  .description-team img {
    width: 475px;
    top: 150px;
  }
  .team {
    padding-top: 20px;
  }

  .team-flex {
    margin-right: 2vw;
    margin-left: 2vw;
  }
  .team-flex img {
    height: 120px;
    width: 120px;
    margin-top: 5px;
    flex: 0 0 50%;
    margin-right: 10px;
  }
  .member-name {
    margin-left: 6%;
  }
}
</style>
