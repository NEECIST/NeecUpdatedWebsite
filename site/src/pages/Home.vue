<template>
  <div class="home-app">
    <div class="carousel" v-if="initialized">
      <Carousel :settings="settings" :breakpoints="breakpoints" />
    </div>
    <div v-else :style="{minHeight: '600px'}">
      <PulseLoader :color="'#009DE0'"></PulseLoader>
    </div>
    <div class="announcement">
      <a class="hover-underline-animation" href="/form">Inscreve-te agora na nossa newsletter!</a>
    </div>

    <div class="container" :style="{ padding: '10px', paddingBottom: '200px' }">
      <div class="activities-row">
        <div class="col iconss" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'row-reverse' }">
          <div class="icon-holder" :style="{ display: 'flex', width: '50%', paddingRight: '10vw', justifyContent: 'center' }">
            <i class="fa-solid fa-people-group fa-10x icon"></i>
          </div>
        </div>
        <div class="vl"></div>
        <div class="col" data-aos="fade-left">
          <div class="algo-card">
            <h2>Quem somos?</h2>
            <p>
              O Núcleo de Estudantes de Electrotecnia e Computadores é uma associação sem fins lucrativos que reúne os estudantes de LEEC e MEEC do IST. Somos formados por alunos que, através do seu
              trabalho voluntário e motivados pela tecnologia e associativismo, procuram trazer novas ideias, projetos e iniciativas contribuindo para o desenvolvimento de todos os alunos.
            </p>
          </div>
        </div>
      </div>
      <div class="activities-row">
        <div class="col" data-aos="fade-right" :style="{ flexDirection: 'row-reverse' }">
          <div class="algo-card">
            <h2>Workshops</h2>
            <p>Queres por em prática alguns dos conhecimentos das aulas? O NEEC ajuda-te. Realizamos workshops de Eletrónica, Soldadura, Programação, Soft-Skills entre muitos outros...</p>
            <p>
              <a class="address-text" href="https://linktr.ee/neecist"><i class="fa-solid fa-gear fa-xl" :style="{ paddingRight: '4px' }"></i>Inscreve-te!</a>
            </p>
          </div>
        </div>
        <div class="vl"></div>
        <div class="col iconss" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'row' }">
          <div class="icon-holder" :style="{ display: 'flex', width: '50%', paddingLeft: '10vw', justifyContent: 'center' }">
            <i class="fa-solid fa-gear fa-10x icon"></i>
          </div>
        </div>
      </div>
      <div class="activities-row">
        <div class="col iconss" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'row-reverse' }">
          <div class="icon-holder" :style="{ display: 'flex', width: '50%', paddingRight: '10vw', justifyContent: 'center' }">
            <i class="fa-solid fa-folder-open fa-10x icon"></i>
          </div>
        </div>
        <div class="vl"></div>
        <div class="col" data-aos="fade-left">
          <div class="algo-card">
            <h2>Drive MEEC</h2>
            <p>
              Acesso a todos os recursos necessários para conseguires trabalhar nas tuas cadeiras! Aulas, problemas, testes e exames, tanto de licenciatura como de mestrado. Também podes contribuir
              com material teu!
            </p>
            <p>
              <a class="address-text" href="https://drive.google.com/drive/u/3/folders/1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz"
                ><i class="fa-solid fa-folder-open fa-xl" :style="{ paddingRight: '4px' }"></i>drive.neecist.org</a
              >
            </p>
          </div>
        </div>
      </div>
      <div class="activities-row">
        <div class="col" data-aos="fade-right" :style="{ flexDirection: 'row-reverse' }">
          <div class="algo-card">
            <h2>IST SI</h2>
            <p>
              Queres experienciar o mundo de trabalho? Entra em contacto e candidata-te para estagiar no verão em empresas ligadas a todos os ramos de engenharia, para poderes enriquecer a tua
              experiência profissional.
            </p>
            <p>
              <a class="address-text" href="https://ist-csm.symplicity.com/students/app/home"><i class="fa-solid fa-id-badge fa-xl" :style="{ paddingRight: '4px' }"></i>Explora!</a>
            </p>
          </div>
        </div>
        <div class="vl"></div>
        <div class="col iconss" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'row' }">
          <div class="icon-holder" :style="{ display: 'flex', width: '50%', paddingLeft: '10vw', justifyContent: 'center' }">
            <i class="fa-solid fa-id-badge fa-10x icon"></i>
          </div>
        </div>
      </div>
      <div class="activities-row">
        <div class="col iconss" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'row-reverse' }">
          <div class="icon-holder" :style="{ display: 'flex', width: '50%', paddingRight: '10vw', justifyContent: 'center' }">
            <i class="fa-solid fa-microchip fa-10x icon"></i>
          </div>
        </div>
        <div class="vl"></div>
        <div class="col" data-aos="fade-left">
          <div class="algo-card">
            <h2>NEECLab</h2>
            <p>
              Precisas de ajuda para desenvolver o teu projeto pessoal? O NEECLab é um laboratório de eletrónica com as ferramentas necessárias e uma equipa pronta a ajudar-te a transformares a tua
              ideia num sucesso!
            </p>
          </div>
        </div>
      </div>
      <div class="activities-row">
        <div class="col" data-aos="fade-right" :style="{ flexDirection: 'row-reverse' }">
          <div class="algo-card">
            <h2>NEECTalks</h2>
            <p>
              NEECTalks é um podcast onde discutimos projectos, tecnologia e trazemos convidados experientes de diversos contextos que envolvem a nossa área no formato de uma conversa informal. Se és
              curioso e tens vontade de aprender, junta-te a nós!
            </p>
            <a class="address-text" href="https://www.youtube.com/user/NEECIST" target="_blank">
              <i class="fa-brands fa-youtube fa-2x" :style="{ padding: '4px' }"></i>
            </a>
            <a class="address-text" href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank"><i class="fa-brands fa-spotify fa-2x" :style="{ padding: '4px' }"></i></a>
          </div>
        </div>
        <div class="vl"></div>
        <div class="col iconss" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'row' }">
          <div class="icon-holder" :style="{ display: 'flex', width: '50%', paddingLeft: '10vw', justifyContent: 'center' }">
            <iframe
              v-if="initialized"
              id="NEECtalksPlayer"
              :src="episode"
              allowfullscreen=""
              allow="autoplay; clipboard-write; encrypted-media; fullscreen; picture-in-picture"
              frameBorder="0"
            ></iframe>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import Carousel from "../components/Carousel";

import axios from "axios";
import PulseLoader from "vue-spinner/src/PulseLoader.vue";

export default {
  name: "home-page",
  components: {
    Carousel,
    PulseLoader,
  },
  data() {
    return {
      hovering: -1,
      activities_image: "Activities/WhitePane.jpg",
      initialized: false,
      settings: {
        itemsToShow: 1,
        itemsToScroll: 1,
        wrapAround: true,
        snapAlign: "center",
        transition: 300,
        autoplay: 10000,
        breakpoints: null,
        modelValue: 0,
        mouseDrag: true,
        touchDrag: true,
        pauseAutoplayOnHover: true,
      },
      breakpoints: {
        // 700px and up
        700: {
          itemsToShow: 3.5,
          snapAlign: "center",
        },
        // 1024 and up
        1024: {
          itemsToShow: 5,
          snapAlign: "start",
        },
      },
      episode: "",
    };
  },
  created() {
    const config = {
      headers: {
        Authorization: `Bearer 6d91366b1570f57e18431d3581ed78afe6bb64d7fde38be4b3df3f08fd4b8d83184344a85b0a49925c3a957d58e9764d8ae4bdc2fcdc5952fea7948ba3eaf724488648a354dfd7ab6abf1c1357ece89dce648554c33169c705e5e0d4da2363cb2b7ebde31dc9b8e2a24c61810f109a57c0b59415e5ddb95ee2ee568475c5abd8`,
      },
    };

    axios
      .get("https://api.neec.midas-cloud.xyz/api/anuncios?filters[id_episodio_spotify][$notNull]=true", config)
      .then((response) => {
        this.episode = "https://open.spotify.com/embed/episode/" + response.data.data[0].attributes.id_episodio_spotify;
      })
      .finally(() => {
        this.initialized = true;
      });
  },
};
</script>

<style>
.home-app {
  padding-top: 60px;
  background-color: white;
  position: relative;
}
@font-face {
  font-family: "Vibur";
  src: local("Vibur"), url(../assets/fonts/Vibur/Vibur-Regular.ttf) format("truetype");
}
.address-text {
  color: #303633;
}
.address-text:hover {
  color: #009de0;
}

.about-container {
  padding: 10px;
  background-color: red;
}
.algo-card {
  width: 50%;
  padding-left: 10vw;
  padding-right: 10vw;
}
.icon {
  color: #303633;
}
.icon:hover {
  color: #009de0;
}
.algo-card p {
  font-size: 20px;
}

.vl {
  border-left: 4px solid #dcdcdc;
  height: 100%;
  border-radius: 8px;
}
.col {
  width: 50%;
  display: flex;
}
.about-card {
  display: inline-block;
  background-color: cyan;
  border-radius: 4px;
  width: 25%;
  height: 100%;
  margin: 10px;
}

.card-title {
  background-color: yellow;
  height: 25%;
}
.card-content {
  background-color: white;
  padding-left: 10px;
  padding-right: 10px;
}
.announcement {
  display: flex;
  align-items: center;
  justify-content: center;
  background-color: #303633;
  padding-top: 20px;
  padding-bottom: 20px;

  white-space: nowrap;
}
.announcement a {
  color: white;
  font-size: 2rem;
}
.hover-underline-animation {
  display: inline-block;
  position: relative;
  color: #fff;
}

.hover-underline-animation:after {
  content: "";
  position: absolute;
  width: 100%;
  transform: scaleX(0);
  height: 0.2rem;
  bottom: 0;
  left: 0;
  background-color: #fff;
  transform-origin: bottom right;
  transition: transform 0.25s ease-out;
}

.hover-underline-animation:hover:after {
  transform: scaleX(1);
  transform-origin: bottom left;
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

#NEECtalksPlayer {
  border-radius: 12px;
  width: 75%;
  height: 232px;
}

.carousel {
  width: 100%;
  justify-content: center;
  align-items: center;
}
@media (max-width: 1200px) {
  .icon-holder {
    padding: 0px !important;
    width: 100% !important;
  }
  .col {
    width: 100%;
  }
  .announcement a {
    text-decoration: underline;
  }
  .hover-underline-animation:after {
    display: none;
  }
}
@media (max-width: 990px) {
  .icon-holder {
    padding: 0px !important;
    width: 100% !important;
  }
  .col {
    width: 100%;
  }
  .announcement a {
    text-decoration: underline;
  }
  .hover-underline-animation:after {
    display: none;
  }
}
</style>
