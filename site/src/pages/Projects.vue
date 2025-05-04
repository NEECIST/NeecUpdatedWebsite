<template>
  <div class="projects-page">
    <main class="projects-container">
      <h1 class="main-title">Projetos</h1>

      <div class="project-card" v-for="(card, index) in cardList" :key="index">
        <div class="left-side">
          <img :src="card.image" alt="Imagem do projeto" class="project-image" />
        </div>

        <div class="right-side">
          <p class="project-desc" v-html="card.desc"></p>
          <div class="people-icons">
            <div class="person-icon" v-for="n in 3" :key="n"></div>
          </div>
          <button class="learn-more">Saber mais</button>
        </div>
      </div>
    </main>
  </div>
</template>

<script>
import axios from "axios";
export default {
  name: "ProjectsPage",
  data() {
    return {
      cardList: [],
    };
  },
  methods:{
    linkify(inputText){
      const pattern1 = /(\b(https?|ftp):\/\/[-A-Z0-9+&@#/%?=~_|!:,.;]*[-A-Z0-9+&@#/%=~_|])/gim;
      let text = inputText.replace(pattern1, '<a href="$1" target="_blank">$1</a>');
      const pattern2 = /(^|[^/])(www\.[\S]+(\b|$))/gim;
      return text.replace(pattern2, '$1<a href="http://$2" target="_blank">$2</a>');
    }
  },
  created() {
    axios
      .get("https://api.trello.com/1/lists/62ab561ec85b68533787cf3c/cards?attachments=true")
      .then((response) => {
        this.cardList = response.data.map((item) => ({
          name: item.name,
          image: item.attachments[0]?.url,
          desc: this.linkify(item.desc),
        }));
      });
  },
};
</script>

<style scoped>
.projects-page {
  font-family: 'Roboto', sans-serif;
  background-color: #fef1e6;
  min-height: 100vh;
}

.logo {
  color: white;
  font-weight: bold;
  font-size: 1.2rem;
}

.main-title {
  text-align: center;
  font-size: 3rem;
  font-weight: bold;
  margin: 4rem 0 2rem 0;
}

.projects-container {
  padding: 0 2rem;
}

.project-card {
  display: flex;
  background-color: white;
  border-radius: 16px;
  box-shadow: 0 4px 20px rgba(0,0,0,0.1);
  margin: 2rem 0;
  padding: 1.5rem;
  flex-wrap: wrap;
}

.left-side {
  flex: 1;
  min-width: 200px;
  display: flex;
  align-items: center;
  justify-content: center;
}

.project-image {
  width: 100%;
  max-width: 200px;
  border-radius: 8px;
}

.right-side {
  flex: 2;
  padding: 1rem;
}

.project-desc {
  font-size: 1rem;
  margin-bottom: 1rem;
}

.people-icons {
  display: flex;
  gap: 0.5rem;
  margin-bottom: 1rem;
}

.person-icon {
  width: 40px;
  height: 40px;
  border-radius: 50%;
  background-color: #f9f9f9;
  border: 2px solid #ccc;
}

.learn-more {
  background-color: #f48120;
  color: white;
  font-weight: bold;
  border: none;
  padding: 0.5rem 1.5rem;
  border-radius: 6px;
  cursor: pointer;
}

.learn-more:hover {
  background-color: #d76f1b;
}
</style>