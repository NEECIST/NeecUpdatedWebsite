<template>
  <div class="projects-app">
    <div v-if="initialized" class="projects-holder">
      <div class="card" v-for="(card, card_id) in cardList" :key="card_id">
        <div :style="{ padding: '3vw' }">
          <div class="img-box">
            <img v-if="card.image" :src="card.image" />
          </div>
          <h1 class="card-name">{{ card.name }}</h1>
          <p class="card-desc" v-html="card.desc"></p>
        </div>


        
      </div>
    </div>
    <div v-else>
      <PulseLoader :color="'#009DE0'"></PulseLoader>
    </div>
  </div>
</template>

<script>
import axios from "axios";
import PulseLoader from "../../node_modules/vue-spinner/src/PulseLoader.vue";
export default {
  name: "projects-page",
  data() {
    return {
      initialized: false,
      cardList: [],
    };
  },
  components: {
    PulseLoader,
  },
  methods: {
    curateCardText(List) {
      List.forEach((element) => {
        element.desc = this.linkify(element.desc);
      });
    },
    linkify(inputText) {
      //eslint-disable-next-line
      const pattern1 = /(\b(https?|ftp):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/gim;
      let text = inputText.replace(pattern1, '<a class= "workpls" href="$1" target="_blank">$1</a>');
      //eslint-disable-next-line
      const pattern2 = /(^|[^\/])(www\.[\S]+(\b|$))/gim;
      text = text.replace(pattern2, '$1<a class= "workpls" href="http://$2" target="_blank">$2</a>');

      return text;
    },
  },
  mounted() {
    this.curateCardText(this.cardList);
  },
  created() {
    axios
      .get("https://api.trello.com/1/lists/62ab561ec85b68533787cf3c/cards?attachments=true")
      .then((response) => {
        response.data.forEach((element) => {
          this.cardList.push({ name: element.name, image: element.attachments[0].url, desc: this.linkify(element.desc) });
        });
      })
      .finally(() => {
        this.initialized = true;
      });
  },
};
</script>

<style scoped>
@import url("https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500&display=swap");
.projects-app {
  /* background: rgba(0,157,224,1); */
  /* //background: linear-gradient(193deg, rgba(255,255,255,1) 12%, rgba(0,157,224,1) 100%); */
  font-family: "Roboto", sans-serif;
}
.workpls {
  color: #ea0000;
}
.projects-holder {
  padding-bottom: 190px;
  padding-top: 100px;
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
  width: 100%;
  justify-content: space-evenly;
}

.card {
  border-radius: 32px;
  box-shadow: rgba(0, 0, 0, 0.25) 0px 54px 55px, rgba(0, 0, 0, 0.12) 0px -12px 30px, rgba(0, 0, 0, 0.12) 0px 4px 6px, rgba(0, 0, 0, 0.17) 0px 12px 13px, rgba(0, 0, 0, 0.09) 0px -3px 5px;
  backdrop-filter: blur(15px);
  text-align: center;
  margin-top: 2vw;
  margin-bottom: 2vw;
  width: 30%;
  color: #ffffff;
  background-color: #303633;
}

.card .img-box {
  height: 45vh;
  align-items: center;
  display: flex;
  justify-content: center;
}

.card img {
  width: auto;
  border-radius: 12px;
  height: auto;
  object-fit: contain;
  max-width: 100%;
  max-height: 100%;
}

.card-name {
  font-family: "Michroma", sans-serif;
  color: darkred;
  font-size: xxx-large;
}
.card-desc {
  font-size: 1.2rem;
  opacity: 0.8;
  white-space: break-spaces;
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
  .description-projects img {
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
  .description-projects {
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
  .description-projects img {
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

<style>
a {
  overflow-wrap: anywhere;
}
</style>
