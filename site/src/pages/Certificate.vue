<template>
  <div class="certificate-app">
    <div v-if="initialized">
      <h2>Certificado de Participação</h2>
      <div>
        <img :src="certificateUrl" alt="certificate Image" />
      </div>
    </div>
    <div v-else>
      <PulseLoader :color="'#009DE0'"></PulseLoader>
    </div>

    <div>{{ this.error }}</div>
  </div>
</template>

<script>
import axios from "axios";
//import { url } from 'inspector';
import PulseLoader from "vue-spinner/src/PulseLoader.vue";
import { createCanvas } from "canvas";
export default {
  name: "certificate-page",
  components: {
    PulseLoader,
  },
  data() {
    return {
      initialized: false,
      error: null,
      certificateUrl: null,
    };
  },
  created() {
    const config = {
      headers: {
        Authorization: `Bearer 6d91366b1570f57e18431d3581ed78afe6bb64d7fde38be4b3df3f08fd4b8d83184344a85b0a49925c3a957d58e9764d8ae4bdc2fcdc5952fea7948ba3eaf724488648a354dfd7ab6abf1c1357ece89dce648554c33169c705e5e0d4da2363cb2b7ebde31dc9b8e2a24c61810f109a57c0b59415e5ddb95ee2ee568475c5abd8`,
      },
    };
    const canvas = createCanvas();
    axios
      .get("https://api.neecist.org/api/certificados?filters[cert_uid][$eq]=" + this.$route.params.id + "&populate=Background&populate=signature", config)
      .then((response) => {
        let url_back = "https://api.neec.midas-cloud.xyz" + response.data.data[0].attributes.Background.data.attributes.url;
        let background_w = response.data.data[0].attributes.Background.data.attributes.width;
        let background_h = response.data.data[0].attributes.Background.data.attributes.height;
        let name = response.data.data[0].attributes.participant;
        let color = response.data.data[0].attributes.color;

        // Create certificate
        // Get background size
        canvas.width = background_w;
        canvas.height = background_h;

        const ctx = canvas.getContext("2d");

        // Draw background
        const background = new Image();
        background.crossOrigin = "Anonymous";
        let that = this;
        background.onload = function () {
          ctx.drawImage(background, 0, 0, background_w, background_h);
          ctx.font = "bold 50px Arial";
          ctx.fillStyle = color;
          ctx.textAlign = "center";
          ctx.fillText(name, background_w / 2, background_h / 2 + 100);
          that.certificateUrl = canvas.toDataURL();
          that.initialized = true;
        };
        background.src = url_back;
      })
      .finally(() => {
        //this.initialized = true;
      });
  },

  //console.log("https://api.trello.com/1/cards/" + this.$route.params.id + "?attachments=true")
  //axios.get("https://api.trello.com/1/cards/" + this.$route.params.id + "?attachments=true")
  //    .then(response => {
  //        console.log(response.data)
  //        this.certificateUrl = response.data.attachments[0].url
  //    }).catch(() => {
  //        this.error = "Unable to find certificate"
  //    }).finally(() => {
  //        this.initialized = true
  //    });
  //}
};
</script>

<style scoped>
@import url("https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500&display=swap");

.certificate-app {
  padding-top: 10vh;
  padding-bottom: 7vh;
  font-family: Roboto;
}

.certificate-app img {
  max-width: 80vw;
  max-height: 77vh;
  box-shadow: 0 0 7px 3px #888;
}

@media only screen and (max-width: 1080px) {
  .certificate-app {
    padding-top: 80px;
  }
}
</style>
<style>
#page {
  display: flex;
  flex-direction: column;
}

@media only screen and (max-width: 1080px) {
  .contacts-comp .row .col-md-4:first-child {
    display: none;
  }
}

.contacts-comp {
  position: unset;
  margin-top: auto;
}
</style>
