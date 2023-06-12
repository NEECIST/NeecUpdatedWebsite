<template>
  <div v-if="initialized">
    <carousel :settings="settings" :breakpoints="breakpoints" :paginationPosition="top" :count="cards.length">
      <slide v-for="slide in cards" :key="slide">
        <a v-if="slide.page_url" class="carousel__item" :href="slide.page_url" target="_blank">
          <div class="carousel__item" :style="{ backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.527),rgba(0, 0, 0, 0.5)) ,url(${slide.image})` }">
            <div v-if="slide.text" class="carousel__main__text">
              {{ slide.text }}
            </div>
          </div>
        </a>
        <div class="carousel__item" v-else>
          <div class="carousel__item" :style="{ backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.527),rgba(0, 0, 0, 0.5)) ,url(${slide.image})` }">
            <div v-if="slide.text" class="carousel__main__text">
              {{ slide.text }}
            </div>
          </div>
        </div>
      </slide>

      <template #addons>
        <pagination />
      </template>
    </carousel>
  </div>
</template>

<script>
import "vue3-carousel/dist/carousel.css";
import { Carousel, Slide, Pagination } from "vue3-carousel";
import axios from "axios";
export default {
  name: "carousel-component",
  props: {
    settings: {
      type: Object,
      default: () => ({
        itemsToShow: 1,
        itemsToScroll: 1,
        wrapAround: true,
        snapAlign: "start",
        transition: 1000,
        autoplay: 3000,
        breakpoints: null,
        modelValue: 0,
      }),
    },
    breakpoints: {
      type: Object,
      default: () => ({
        700: {
          itemsToShow: 3.5,
          snapAlign: "center",
        },
        1024: {
          itemsToShow: 5,
          snapAlign: "start",
        },
      }),
    },
  },
  components: {
    Carousel,
    Slide,
    Pagination,
  },
  data() {
    return {
      initialized: false,
      cards: [],
    };
  },
  created() {
    const config = {
      headers: {
        Authorization: `Bearer 6d91366b1570f57e18431d3581ed78afe6bb64d7fde38be4b3df3f08fd4b8d83184344a85b0a49925c3a957d58e9764d8ae4bdc2fcdc5952fea7948ba3eaf724488648a354dfd7ab6abf1c1357ece89dce648554c33169c705e5e0d4da2363cb2b7ebde31dc9b8e2a24c61810f109a57c0b59415e5ddb95ee2ee568475c5abd8`,
      },
    };

    axios
      .get("https://api.neec.midas-cloud.xyz/api/anuncios?populate=image", config)
      .then((response) => {
        response.data.data.forEach((element) => {
          const imgUrl = "https://api.neec.midas-cloud.xyz" + element.attributes.image.data.attributes.url;
          this.cards.push({ text: element.attributes.title, image: imgUrl, page_url: element.attributes.url, order_id: element.attributes.order_id });
        });
        this.cards.sort((a, b) => a.order_id - b.order_id);
      })
      .finally(() => {
        this.initialized = true;
      });
  },
};
</script>

<style>
.carousel__item {
  min-height: 600px;
  min-width: 100%;
  display: flex;
  justify-content: center;
  align-items: center;
  background-size: cover;
  background-repeat: no-repeat;
  background-position: center;
}

.carousel__main__text {
  font-size: 52px;
  margin-bottom: -320px;
  color: white;
  text-align: center;
  font-weight: bold;
}
.carousel__pagination-button {
  background-color: #dcdcdc;
  height: 10px;
  width: 40px;
}
.carousel__pagination-button--active {
  background-color: #009de0;
}

.carousel_photo {
  width: 5vw;
  height: 5vw;
}
</style>
