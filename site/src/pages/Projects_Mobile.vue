<template>
  <div class="projects-page">
    <main class="projects-container">

      <div class="project-card" v-for="(card, index) in cardList" :key="index" :class="{ 'reverse': index % 2 === 1 }">
        <div class="left-side">
          <img :src="card.image" alt="Imagem do projeto" class="project-image" />
        </div>

        <div class="right-side">
          <p class="project-desc" v-html="card.desc"></p>
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
  max-width: 100%;
  box-sizing: border-box;
  overflow: hidden;
}

.project-card.reverse {
  flex-direction: row-reverse;
}

.left-side {
  flex: 1;
  min-width: 150px;
  display: flex;
  align-items: center;
  justify-content: center;
}

.project-image {
  width: 150px;
  height: 150px;
  border-radius: 8px;
  object-fit: cover;
  overflow: hidden;
}

.right-side {
  flex: 2;
  padding: 1rem;
  max-width: 100%;
  word-wrap: break-word;
  overflow-wrap: break-word;
  box-sizing: border-box;

  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  text-align: center ;
}

.project-desc {
  font-size: 1rem;
  margin-bottom: 0;
  word-wrap: break-word;
  overflow-wrap: break-word;
  text-align: center;
  max-width: 100%;
  overflow: hidden;
}

@media (max-width: 768px) {
  .project-card {
    flex-direction: column; 
    align-items: center;
    max-width: 100%;
  }

  .project-card.reverse-card {
    flex-direction: column; 
  }

  .left-side {
    min-width: 100%;
    display: flex;
    justify-content: center;
  }

  .project-image {
    width: 150px;
    height: 150px;
    margin-bottom: 1rem;
  }

  .right-side {
    padding: 1rem 0;
    align-items: center;
    text-align: center;
    max-width: 90%;
  }

  .project-desc {
    font-size: 1rem;
    margin-bottom: 0;
    word-wrap: break-word;
    overflow-wrap: break-word;
    text-align: center;
  }
}
</style>