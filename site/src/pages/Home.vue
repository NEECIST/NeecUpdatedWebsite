<template>
  <div class="home-app">
    <div :style="{ minHeight: '600px' }">
      <div class="carousel" v-if="initialized">
        <Carousel :settings="settings" :breakpoints="breakpoints" />
      </div>
      <div v-else class="loading">
        <PulseLoader :color="'#009DE0'"></PulseLoader>
      </div>
    </div>
    <div class="announcement">
      
    </div>

    <div class="container" :style="{ padding: '10px', paddingBottom: '200px' }">
      <div class="activities-row" id="QuemSomos">
        <div class="section-title" data-aos="fade-top">
          <h1>Quem Somos?</h1>
        </div>
        <div class="row">
          <div class="col-div-2" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'row-reverse' }">
            <div class="image-border" :style="{ width: 'calc(75% - 1rem)', height: 'auto'}">
              <img src="https://www.thepattersonfoundation.org/media/zoo/images/picture_8c175f2be82708fafb06ef854755f14a.jpg" alt="Sample image">
            </div>
          </div>
          <div class="col-div-2" data-aos="fade-left">
            <div class="algo-card">
              <p>
                O Núcleo de Estudantes de Electrotecnia e Computadores é uma associação sem fins lucrativos que reúne os estudantes de LEEC e MEEC do IST. Somos formados por alunos que, através do seu
                trabalho voluntário e motivados pela tecnologia e associativismo, procuram trazer novas ideias, projetos e iniciativas contribuindo para o desenvolvimento de todos os alunos.
              </p>
            </div>
          </div>
        </div>
      </div>

      <hr> <!-- Horizontal Divider -->

      <div class="activities-row" id="DriveLMEEC">
        <div class="section-title" data-aos="fade-top">
          <h1>Drive de L/MEEC</h1>
        </div>
        <div class="row">
          <div class="col-div-2" data-aos="fade-right" :style="{ flexDirection: 'row-reverse' }">
            <div class="algo-card">
              <p>
                Nesta drive poderás encontrar todo o material de apoio às unidades curriculares de L/MEEC,
                como, por exemplo, slides, exercícios e exames resolvidos por alunos, entre outros.
                Esta drive é gerida exclusivamente pelo NEECIST e é atualizada regularmente com o material mais recente,
                no entanto, são aceites materiais de outros alunos de L/MEEC (e outros, caso aplicável).
                Para partilhar estes materiais connosco basta colocá-los na pasta
                <a class="address-text" target="blank" href="https://drive.google.com/drive/folders/1PjrWL1Rpvy7qDEI-HsP_2MhN0wr0BZ5l">Uploads</a>
                ou enviá-los por email para
                <a class="address-text" href="mailto:drive@neecist.org">drive@neecist.org</a>.
                Caso sejas o dono deste material serás devidamente creditado.
              </p>
              <p>
                <a class="address-text" target="blank" href="https://drive.neecist.org/"><i class="fa-solid fa-folder-open fa-xl" :style="{ paddingRight: '4px' }"></i>Acede à Drive!</a>
              </p>
            </div>
          </div>
          <div class="col-div-2" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'row' }">
            <div class="image-border" :style="{ width: 'calc(75% - 1rem)', height: 'auto'}">
              <img src="https://static.bandainamcoent.eu/high/pac-man/brand-setup/pac_thumb_brand_624x468_4b.jpg" alt="Sample image">
            </div>
          </div>
        </div>
        
      </div>

      <hr> <!-- Horizontal Divider -->

      <div class="activities-row" id="Projetos">
        <div class="section-title" data-aos="fade-top">
          <h1>Projetos</h1>
        </div>

        <div class="row">
          <div class="col-div-2" data-aos="fade-right" :style="{flexDirection: 'column'}">
            <div class="row">
              <div class="col-div-2">
                <div class="image-border" :style="{ width: 'calc(100% - 1rem)', height: 'auto'}">
                  <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
                </div>
              </div>
              <div class="col-div-2">
                <div class="image-border" :style="{ width: 'calc(100% - 1rem)', height: 'auto'}">
                  <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
                </div>
              </div>
            </div>
            <div class="row">
              <div class="image-border" :style="{ width: 'calc(40% - 0.5rem)', height: 'auto'}">
                <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
              </div>
            </div>
          </div>
          <div class="col-div-2" data-aos="fade-left">
            <div class="image-border" :style="{ width: 'calc(80% - 0.5rem)', height: 'auto'}">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
        </div>
      </div>

      <hr> <!-- Horizontal Divider -->

      <div class="activities-row" id="Equipas">
        <div class="section-title" data-aos="fade-top">
          <h1>Equipas</h1>
        </div>
        
        <!-- 2 Rows to form the layout -->
        <div class="row">
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="teams-text bottom">
              MULTIMÉDIA
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="teams-text bottom">
              DESIGN
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="teams-text bottom">
              DIVULGAÇÃO
            </div>
          </div>
        </div>
        
        <div class="row">
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="teams-text top">
              IT
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="teams-text top">
              PROJETOS
            </div>
          </div>
          <div class="col-div-5" data-aos="fade-top" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
        </div>
      </div>

      <hr> <!-- Horizontal Divider -->

      <div class="activities-row" id="Soon">
        <div class="section-title" data-aos="fade-top">
          <h1>Em Breve</h1>
        </div>
        <div class="row">
          <div class="col-div-2" data-aos="fade-right" :style="{ flexDirection: 'row-reverse' }">
            <div class="algo-card">
              <p>
                ESTAVAM A RECLAMAR QUE O TEXTO ANTERIOR ESTAVA EM LATIM???? Qual é o mal?
                Era só um texto aleatório,
                sem sentido — como qualquer outro texto de enchimento — mas como estava em latim,
                parece que incomodou mais do que o normal.
                Não que alguém esperasse perceber o que lá estava, claro...
                Mas aparentemente, se é para ser texto sem nexo,
                que ao menos seja em português, não é?

                Então cá está: um novo texto aleatório,
                desta vez em bom português de Portugal, só para acalmar os ânimos.
                Continuamos sem ter nada de concreto para mostrar neste espaço,
                mas pelo menos agora ninguém se vai queixar que está numa língua morta.

                Obrigado pela paciência (ou pela persistência em reclamar).
                Em breve — esperemos — haverá conteúdo digno deste espaço.
                Até lá, fiquem com este desabafo.
              </p>
              <p>
                <a class="address-text" target="blank" href="https://www.youtube.com/watch?v=dQw4w9WgXcQ"><i class="fa-solid fa-id-badge fa-xl" :style="{ paddingRight: '4px' }"></i>Explora!</a>
              </p>
            </div>
          </div>
          <div class="col-div-2" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'row' }">
            <div class="image-border" :style="{ width: 'calc(75% - 1rem)', height: 'auto'}">
              <img src="https://i.imgflip.com/54d9lj.png?a485856" alt="Sample image">
            </div>
          </div>
        </div>
      </div>

      <hr> <!-- Horizontal Divider -->

      <div class="activities-row" id="Patrocinadores">
        <div class="section-title" data-aos="fade-top">
          <h1>Patrocinadores</h1>
        </div>

        <!-- 2 Rows Of Sponsors -->
        <div class="row">
          <div class="col-div-4" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          
          <div class="col-div-4" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          
          <div class="col-div-4" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          
          <div class="col-div-4" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
        </div>

        <div class="row">
          <div class="col-div-4" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          
          <div class="col-div-4" data-aos="fade-left" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          
          <div class="col-div-4" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border">
              <img src="https://i.ytimg.com/vi/hAsZCTL__lo/maxresdefault.jpg" alt="Sample image">
            </div>
          </div>
          
          <div class="col-div-4" data-aos="fade-right" :style="{ display: 'flex', flexDirection: 'column' }">
            <div class="image-border" :style="{ width: 'calc(75% - 1rem)', height: 'auto'}">
              <img src="https://static.bandainamcoent.eu/high/pac-man/brand-setup/pac_thumb_brand_624x468_4b.jpg" alt="Sample image">
            </div>
          </div>
        </div>
      </div>

      <!-- Old NEECTalks -->
      <!-- <hr> Horizontal Divider -->
      <!--
      <div class="activities-row">
        <div class="col" data-aos="fade-right" :style="{ flexDirection: 'row-reverse' }">
          <div class="algo-card">
            <h2>NEECTalks</h2>
            <p>
              NEECTalks é um podcast onde discutimos projectos, tecnologia
              e trazemos convidados experientes de diversos contextos que envolvem a nossa área no formato de uma conversa informal.
              Se és curioso e tens vontade de aprender, junta-te a nós!
            </p>
            <a class="address-text" href="https://www.youtube.com/user/NEECIST" target="_blank">
              <i class="fa-brands fa-youtube fa-2x" :style="{ padding: '4px' }"></i>
            </a>
            <a class="address-text" href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank"><i class="fa-brands fa-spotify fa-2x" :style="{ padding: '4px' }"></i></a>
          </div>
        </div>
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
      -->

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
      .get("https://api.neecist.org/api/anuncios?filters[id_episodio_spotify][$notNull]=true", config)
      /*.then((response) => {                 Comentei pq tava a dar erro
        this.episode = "https://operesponsen.spotify.com/embed/episode/" + response.data[0].attributes.id_episodio_spotify;
      })*/
      .finally(() => {
        this.initialized = true;
      });
  },
};
</script>

<style>
.home-app {
  padding-top: 60px;
  background-color: #FFF4E8;
  position: relative;
}
@font-face {
  font-family: "Montserrat";
  src: local("Montserrat"), url(../assets/fonts/Montserrat/Montserrat-Regular.ttf) format("truetype");
}
.address-text {
  font-style: italic;
  color: #252525;
}
.address-text:hover {
  color: #009de0;
}

.algo-card {
  width: 100%;
  padding-left: 10%;
  padding-right: 10%;
}
.icon-holder {
  justify-content: center;
  align-items: center;
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

.row {
  width: 100%;
  display: flex;
  align-items: stretch;    /* Make children stretch to the row’s height */
  justify-content: center; /* Start columns from center */
}

.col-div-2 {
  width: 50%;
  height: auto;
  display: flex;
  justify-content: center;
  align-items: center;
}
.col-div-4 {
  width: 22%; /* 22 and not 25 to leave some space on the borders and bring them closer */
  height: auto;
  display: flex;
  justify-content: center;
  align-items: center;
}
.col-div-5 {
  width: 18%; /* 18 and not 20 to leave some space on the borders and bring them closer */
  height: auto;
  display: flex;
  justify-content: center;
  align-items: center;
}

.announcement {
  display: flex;
  align-items: center;
  justify-content: center;
  background-color: #252525;
  padding-top: 20px;
  padding-bottom: 20px;

  margin-bottom: 20px;

  white-space: nowrap;
}
.announcement a {
  color: #FFF4E8;
  font-size: 2rem;
}
.hover-underline-animation {
  display: inline-block;
  position: relative;
  color: #FFF4E8;
}

.hover-underline-animation:after {
  content: "";
  position: absolute;
  width: 100%;
  transform: scaleX(0);
  height: 0.2rem;
  bottom: 0;
  left: 0;
  background-color: #FFF4E8;
  transform-origin: bottom right;
  transition: transform 0.25s ease-out;
}

.hover-underline-animation:hover:after {
  transform: scaleX(1);
  transform-origin: bottom left;
}

.section-title {
  width: 100%;
  display: flex;
  justify-content: center;
  align-items: center;
  margin-bottom: 20px; /* Optional spacing below title */
}

.activities-row {
  height: auto;
  display: flex;
  flex-wrap: wrap; /* This allows items to stack */
  justify-content: center;
  align-items: flex-start;
}
.teams-text {
  width: 100%;
  text-align: center;
  font-size: 1.5rem;
  margin: 10px 0; /* Optional spacing below title */
}
.teams-text.bottom {
  margin-top: auto; /* pushes itself to the bottom of the flex column */
}
.teams-text.top {
  margin-bottom: auto; /* pushes itself to the bottom of the flex column */
}

.container hr {
  border: none;
  height: 5px;
  border-radius: 12px; /* Round corners */
  background: #252525;
  margin: 60px 15px;
}

/* Square shapes that hold images */
.image-border {
  --border-width: 7px;
  width: 160px; /* image width + border*2 */
  height: 160px;
  padding: var(--border-width);
  background: linear-gradient(-45deg, #115CA9, #8F439D);
  display: inline-block;
  box-sizing: border-box;
  margin: 10px 0;
  border-radius: 12px; /* Keep square shape */
}
.image-border img {
  width: 100%;
  height: 100%;
  object-fit: cover;
  display: block;
  border-radius: 5px; /* Keep square shape */
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
  .col-div-4 {
    width: 100%;
  }
  .col-div-5 {
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
  .col-div-4 {
    width: 100%;
  }
  .col-div-5 {
    width: 100%;
  }
  .announcement a {
    text-decoration: underline;
  }
  .hover-underline-animation:after {
    display: none;
  }
}

.loading {
  min-height: 560px;
  display: flex;
  align-items: center;
  justify-content: center;
  background-color: #ececec;
  margin: 20px;
  border-radius: 35px;
  animation: 1s infinite alternate cubic-bezier(0.45, 0.05, 0.55, 0.95) breathing-color--dark;
}

@keyframes breathing-color--dark {
  from {
    background-color: hsl(0 0% 80% / 1);
  }
  to {
    background-color: hsl(0 0% 95% / 1);
  }
}
</style>