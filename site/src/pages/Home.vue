<template>
  <main class="home-page">
    <section class="home-hero" aria-label="NEECIST">
      <img class="home-hero__image" :src="heroImage" alt="Equipa do NEECIST" />
      <div class="home-hero__overlay"></div>
    </section>

    <section class="home-section home-section--light">
      <div class="home-section__content">
        <h2>{{ content.about.title[currentLocale] }}</h2>
        <p>{{ content.about.text[currentLocale] }}</p>
      </div>
    </section>

    <section class="home-section home-section--blue">
      <div class="home-section__content home-section__content--wide">
        <h2>{{ content.projects.title[currentLocale] }}</h2>

        <div class="project-carousel" aria-label="Projetos">
          <button
            v-for="project in projects"
            :key="project.id"
            class="project-card"
            type="button"
            @click="openProject(project)"
          >
            <img class="project-card__image" :src="project.image" :alt="project.title" />
            <span class="project-card__title">{{ project.title }}</span>
          </button>
        </div>
      </div>
    </section>

    <section class="home-section home-section--cream">
      <div class="home-section__content home-section__content--wide">
        <h2>{{ content.news.title[currentLocale] }}</h2>

        <div class="news-grid">
          <button
            v-for="newsItem in newsItems"
            :key="newsItem.id"
            class="news-card"
            type="button"
            @click="openNews(newsItem)"
          >
            <span class="news-card__label">{{ content.news.latest[currentLocale] }}</span>
            <h3>{{ newsItem.title[currentLocale] }}</h3>
            <p>{{ newsItem.excerpt[currentLocale] }}</p>
          </button>
        </div>
      </div>
    </section>

    <section class="home-section home-section--dark">
      <div class="home-section__content">
        <h2>A decidir...</h2>
        <p>Sponsors + Contacto ou só Contacto?</p>
      </div>
    </section>
  </main>
</template>

<script>
import heroImage from "../assets/brickWall.png";
import banaNEECImage from "../assets/Projects/BanaNEEC.jpg";
import blinkerImage from "../assets/Projects/blinker.jpg";
import neecReactImage from "../assets/Projects/NEECReact.jpg";
import neecSimonImage from "../assets/Projects/NEECSimon.jpg";
import neecQuickImage from "../assets/Projects/NEECuick.jpg";

export default {
  name: "home-page",
  data() {
    return {
      heroImage,
      currentLocale: "pt",
      content: {
        about: {
          title: {
            pt: "Sobre Nós",
            en: "About Us",
          },
          text: {
            pt: "O Núcleo de Estudantes de Electrotecnia e Computadores é uma associação sem fins lucrativos que reúne os estudantes de LEEC e MEEC do IST. Somos formados por alunos que, através do seu trabalho voluntário e motivados pela tecnologia e associativismo, procuram trazer novas ideias, projetos e iniciativas contribuindo para o desenvolvimento de todos os alunos.",
            en: "The Núcleo de Estudantes de Electrotecnia e Computadores is a non-profit organization representing IST’s LEEC and MEEC students. Driven by a passion for technology and student engagement, our team of volunteers works to launch innovative projects and initiatives that foster personal and professional growth for the entire student body.",
          },
        },
        projects: {
          title: {
            pt: "Projetos",
            en: "Projects",
          },
        },
        news: {
          title: {
            pt: "Notícias",
            en: "News",
          },
          latest: {
            pt: "Mais recente",
            en: "Latest",
          },
        },
      },
      projects: [
        {
          id: "bananeec",
          title: "BanaNEEC",
          image: banaNEECImage,
          target: null,
        },
        {
          id: "blinker",
          title: "Blinker",
          image: blinkerImage,
          target: null,
        },
        {
          id: "neec-react",
          title: "NEECReact",
          image: neecReactImage,
          target: null,
        },
        {
          id: "neec-simon",
          title: "NEECSimon",
          image: neecSimonImage,
          target: null,
        },
        {
          id: "neec-quick",
          title: "NEECuick",
          image: neecQuickImage,
          target: null,
        },
      ],
      newsItems: [
        {
          id: "news-1",
          title: {
            pt: "Notícia 1",
            en: "News 1",
          },
          excerpt: {
            pt: "Lorem ipsum dolor sit amet",
            en: "Lorem ipsum dolor sit amet",
          },
          target: null,
        },
        {
          id: "news-2",
          title: {
            pt: "Notícia 2",
            en: "News 2",
          },
          excerpt: {
            pt: "Lorem ipsum dolor sit amet",
            en: "Lorem ipsum dolor sit amet",
          },
          target: null,
        },
      ],
    };
  },
  methods: {
    openProject(project) {
      if (!project.target) {
        return;
      }

      this.$router.push(project.target);
    },
    openNews(newsItem) {
      if (!newsItem.target) {
        return;
      }

      this.$router.push(newsItem.target);
    },
  },
};
</script>

<style scoped>
.home-page {
  background: #fff4e8;
  padding-top: 60px;
}

.home-page,
.home-page * {
  box-sizing: border-box;
}

.home-hero {
  height: calc(100vh - 60px);
  min-height: 520px;
  position: relative;
  overflow: hidden;
  width: 100%;
}

.home-hero__image {
  display: block;
  height: 100%;
  object-fit: cover;
  object-position: center;
  width: 100%;
}

.home-hero__overlay {
  background: linear-gradient(180deg, rgba(37, 37, 37, 0.1), rgba(37, 37, 37, 0.28));
  inset: 0;
  position: absolute;
}

.home-section {
  align-items: flex-start;
  display: flex;
  min-height: 40vh;
  padding: 64px 8vw;
  text-align: left;
  width: 100%;
}

.home-section__content {
  max-width: 980px;
  width: 100%;
}

.home-section__content--wide {
  max-width: 1440px;
}

.home-section h2 {
  color: inherit;
  font-size: clamp(2rem, 4vw, 4rem);
  font-weight: 700;
  line-height: 1.05;
  margin: 0 0 20px;
}

.home-section p {
  color: inherit;
  font-size: clamp(1.05rem, 2vw, 1.35rem);
  line-height: 1.55;
  margin: 0;
  max-width: 680px;
}

.home-section--light p {
  max-width: 50vw;
}

.home-section--light {
  background: #ffffff;
  color: #252525;
}

.home-section--blue {
  background: #009de0;
  color: #ffffff;
}

.home-section--cream {
  background: #fff4e8;
  color: #252525;
}

.home-section--dark {
  background: #252525;
  color: #fff4e8;
}

.project-carousel {
  background: transparent;
  display: flex;
  gap: 24px;
  margin-top: 36px;
  overflow-x: auto;
  padding: 4px 0px 18px;
  scroll-padding-inline: 0;
  scroll-snap-type: x mandatory;
  scrollbar-color: rgba(255, 255, 255, 0.7) #009de0;
}

.project-carousel::-webkit-scrollbar {
  height: 10px;
}

.project-carousel::-webkit-scrollbar-track {
  background: #009de0;
}

.project-carousel::-webkit-scrollbar-thumb {
  background: rgba(255, 255, 255, 0.7);
  border-radius: 999px;
}

.project-card {
  appearance: none;
  background: #ffffff;
  border: 0;
  border-radius: 8px;
  box-shadow: none;
  color: #252525;
  cursor: pointer;
  flex: 0 0 min(320px, 78vw);
  overflow: hidden;
  padding: 0;
  scroll-snap-align: start;
  text-align: left;
  transition: transform 0.2s ease, box-shadow 0.2s ease;
}

.project-card:hover,
.project-card:focus-visible {
  box-shadow: 0 8px 20px rgba(37, 37, 37, 0.12);
  transform: translateY(-4px);
}

.project-card:focus-visible {
  outline: 3px solid #252525;
  outline-offset: 4px;
}

.project-card__image {
  aspect-ratio: 16 / 10;
  display: block;
  object-fit: cover;
  width: 100%;
}

.project-card__title {
  display: block;
  font-size: 1.15rem;
  font-weight: 700;
  line-height: 1.2;
  padding: 18px 20px 20px;
}

.news-grid {
  display: grid;
  gap: 24px;
  grid-template-columns: repeat(2, minmax(0, 1fr));
  margin-top: 36px;
}

.news-card {
  appearance: none;
  background: #ffffff;
  border: 2px solid rgba(37, 37, 37, 0.12);
  border-radius: 8px;
  color: #252525;
  cursor: pointer;
  min-height: 220px;
  padding: 28px;
  text-align: left;
  transition: border-color 0.2s ease, transform 0.2s ease;
}

.news-card:hover,
.news-card:focus-visible {
  border-color: #009de0;
  transform: translateY(-4px);
}

.news-card:focus-visible {
  outline: 3px solid #252525;
  outline-offset: 4px;
}

.news-card__label {
  color: #009de0;
  display: block;
  font-size: 0.78rem;
  font-weight: 700;
  letter-spacing: 0.08em;
  margin-bottom: 18px;
  text-transform: uppercase;
}

.news-card h3 {
  font-size: clamp(1.35rem, 2.4vw, 2rem);
  line-height: 1.15;
  margin: 0 0 16px;
}

.news-card p {
  font-size: 1rem;
  line-height: 1.5;
  margin: 0;
}

@media only screen and (max-width: 760px) {
  .home-page {
    padding-top: 56px;
  }

  .home-hero {
    height: calc(100vh - 56px);
    min-height: 420px;
  }

  .home-section {
    min-height: 20vh;
    padding: 48px 24px;
  }

  .home-section--light p {
    max-width: 680px;
  }

  .project-carousel {
    gap: 16px;
    scroll-padding-inline: 13vw;
  }

  .project-card {
    flex-basis: 74vw;
    scroll-snap-align: center;
  }

  .news-grid {
    grid-template-columns: 1fr;
  }

  .news-card {
    min-height: 180px;
    padding: 24px;
  }
}
</style>
