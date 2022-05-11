<template>
    <carousel :settings="settings" :breakpoints="breakpoints" :paginationPosition="top">
        <slide v-for="slide in this.cards" :key="slide">
          <a v-if="slide.page_url" class="carousel__item" :href="slide.page_url" target="_blank">
            <div class="carousel__item" :style="{ backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.527),rgba(0, 0, 0, 0.5)) ,url(${require('../assets/' + slide.image)})`}">
                <div v-if="slide.text" class="carousel__main__text">
                  {{slide.text}}

                </div>
            </div>
          </a>
          <div class="carousel__item" v-else>
            <div class="carousel__item" :style="{ backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.527),rgba(0, 0, 0, 0.5)) ,url(${require('../assets/' + slide.image)})`}">
                <div v-if="slide.text" class="carousel__main__text">
                  {{slide.text}}
                </div>
            </div>
          </div>
        </slide>

        <template #addons>
            <pagination />
        </template>
    </carousel>
</template>

<script>
import 'vue3-carousel/dist/carousel.css';
import { Carousel, Slide, Pagination} from 'vue3-carousel';

export default {
  name: "carousel-component",
  props:{
      settings:{
        type: Object,
        default: () => ({
            itemsToShow:1,
            itemsToScroll:1,
            wrapAround:true,
            snapAlign:'start',
            transition:1000,
            autoplay:3000,
            breakpoints:null,
            modelValue:0,
            
        })
      },
      breakpoints:{
        type:Object,
        default: () => ({
            // 700px and up
            700: {
                itemsToShow: 3.5,
                snapAlign: 'center',
            },
            // 1024 and up
            1024: {
                itemsToShow: 5,
                snapAlign: 'start',
            },
        })
      }
      
  },
  components: {
    Carousel,
    Slide,
    Pagination,
  },
  data() {
    return {
    cards:[
        {image: 'Events/webdev.jpg', page_url: 'https://linktr.ee/neecist',text: 'Workshop WebDev'},
        {image: 'Events/discord_invite.png', page_url: 'https://discord.gg/qr7bPe2zJR', text: 'Junta-te ao servidor!'},
        {image: 'Events/NEECathon.png', page_url: 'https://www.youtube.com/watch?v=fkXtXsFnsW8', text: `NEECathon'21`},
        {image: 'Events/brickWall.png', page_url: 'https://www.youtube.com/watch?v=iG2fqPEy2Po', text: `Assiste ao episódio mais recente das NEECTalks`},
    ]
    }
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
  background-position:center;
}

.carousel__main__text {
  font-size: 52px;
  margin-bottom: -320px;
  color: white;
  text-align: center;
  font-weight: bold;
}
.carousel__pagination-button {
  background-color: #DCDCDC;
  height: 10px;
  width: 40px;
}
.carousel__pagination-button--active {
  background-color: #009DE0;
}

.carousel_photo {
  width: 5vw;
  height: 5vw;
}

</style>