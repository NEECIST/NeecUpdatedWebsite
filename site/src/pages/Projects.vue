<template>
  <div class="projects-page">
    <!-- Título -->
    <h1 class="title">Projetos</h1>

    <!-- Grelha de Cards -->
    <div class="card-grid">
      <div
        v-for="(card, index) in cardList"
        :key="index"
        :class="['project-card', index === 4 ? 'wide-card' : '']"
      >
        <img :src="card.image" alt="Imagem do projeto" class="card-image" />

        <div class="card-content">
          <h2 class="card-title">{{ card.name }}</h2>
          <p class="card-desc" v-html="card.desc" />

          <!-- Avatares dos participantes -->
          <div class="avatar-group">
            <img
              v-for="(person, i) in card.people"
              :key="i"
              :src="person.avatar"
              :title="person.name"
              class="avatar"
            />
          </div>

          <!-- Botão -->
          <button @click="openModal(card)" class="btn">
            SABER MAIS
          </button>
        </div>
      </div>
    </div>

    <!-- Modal Detalhes -->
    <div v-if="selectedCard" class="modal-overlay" @click.self="selectedCard = null">
      <div class="modal">
        <button @click="selectedCard = null" class="close-button">×</button>
        <h2>{{ selectedCard.name }}</h2>
        <img :src="selectedCard.image" class="modal-image" />
        <p v-html="selectedCard.desc"></p>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  name: "ProjectsPage",
  data() {
    return {
      cardList: [],
      selectedCard: null,
    };
  },
  methods: {
    linkify(inputText) {
      const pattern1 =
        /(\b(https?|ftp):\/\/[-A-Z0-9+&@#/%?=~_|!:,.;]*[-A-Z0-9+&@#/%=~_|])/gim;
      let text = inputText.replace(
        pattern1,
        '<a href="$1" target="_blank" class="link">$1</a>'
      );
      const pattern2 = /(^|[^/])(www\.[\S]+(\b|$))/gim;
      return text.replace(
        pattern2,
        '$1<a href="http://$2" target="_blank" class="link">$2</a>'
      );
    },
    openModal(card) {
      this.selectedCard = card;
    },
  },
  created() {
    axios
      .get(
        "https://api.trello.com/1/lists/62ab561ec85b68533787cf3c/cards?attachments=true&members=true"
      )
      .then((response) => {
        this.cardList = response.data
          .filter(item => item.name && item.attachments?.length)
          .map((item) => ({
            name: item.name,
            image: item.attachments[0]?.url,
            desc: this.linkify(item.desc),
            people:
              item.members?.map((m) => ({
                name: m.fullName || m.username,
                avatar: m.avatarUrl || `https://ui-avatars.com/api/?name=${m.username}`,
              })) || [],
          }));
      });
  },
};
</script>

<style>
.projects-page {
  padding: 3rem 1rem;
  background: #FFF4E8;
  min-height: 100vh;
  font-family: Arial, sans-serif;
}

.title {
  text-align: center;
  font-size: 3rem;
  font-weight: bold;
  color: #333;
  margin-bottom: 4rem;
  font-family: "Montserrat";
  src: local("Montserrat"), url(../assets/fonts/Montserrat/Montserrat-Regular.ttf) format("truetype");
}

.card-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
  gap: 2rem;
}

.project-card {
  background-color: white;
  border-radius: 16px;
  box-shadow: 0 10px 20px rgba(0, 0, 0, 0.05);
  overflow: hidden;
  display: flex;
  flex-direction: column;
  transition: 0.3s;
}

.project-card:hover {
  transform: translateY(-5px);
  box-shadow: 0 15px 25px rgba(0, 0, 0, 0.1);
}

.wide-card {
  grid-column: span 2;
}

.card-image {
  width: 100%;
  height: 180px;
  object-fit: cover;
}

.card-content {
  padding: 1.5rem;
  display: flex;
  flex-direction: column;
  height: 100%;
}

.card-title {
  font-size: 1.25rem;
  font-weight: 600;
  margin-bottom: 0.5rem;
  color: #222;
}

.card-desc {
  flex: 1;
  color: #666;
  margin-bottom: 1rem;
  font-size: 0.95rem;
}

.avatar-group {
  display: flex;
  gap: 0.5rem;
  margin-bottom: 1rem;
}

.avatar {
  width: 40px;
  height: 40px;
  border-radius: 50%;
  border: 2px solid white;
  object-fit: cover;
}

.btn {
  padding: 0.5rem 1rem;
  background-color: #fb923c;
  color: white;
  font-weight: bold;
  border: none;
  border-radius: 8px;
  cursor: pointer;
  align-self: flex-start;
  transition: background-color 0.2s;
}

.btn:hover {
  background-color: #f97316;
}

.link {
  color: #f97316;
  text-decoration: underline;
}

/* Modal */
.modal-overlay {
  position: fixed;
  inset: 0;
  background-color: rgba(0, 0, 0, 0.5);
  backdrop-filter: blur(3px);
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 1rem;
  z-index: 1000;
}

.modal {
  background-color: white;
  padding: 2rem;
  border-radius: 16px;
  max-width: 600px;
  width: 100%;
  position: relative;
}

.modal h2 {
  margin-bottom: 1rem;
  font-size: 1.5rem;
  color: #222;
}

.modal-image {
  width: 100%;
  height: 220px;
  object-fit: cover;
  border-radius: 8px;
  margin-bottom: 1rem;
}

.close-button {
  position: absolute;
  top: 0.5rem;
  right: 1rem;
  font-size: 2rem;
  background: none;
  border: none;
  color: #999;
  cursor: pointer;
}
</style>