<template>
  <div v-if="initialized">
      <carousel :settings="settings" :breakpoints="breakpoints" :paginationPosition="top" :count="cards.length">
        <slide v-for="slide in cards" :key="slide">
          <a v-if="slide.page_url" class="carousel__item" :href="slide.page_url" target="_blank">
            <div class="carousel__item" :style="{ backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.527),rgba(0, 0, 0, 0.5)) ,url(${slide.image})`}">
                <div v-if="slide.text" class="carousel__main__text">
                  {{slide.text}}

                </div>
            </div>
          </a>
          <div class="carousel__item" v-else>
            <div class="carousel__item" :style="{ backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.527),rgba(0, 0, 0, 0.5)) ,url(${slide.image})`}">
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
  </div>

</template>

<script>
import 'vue3-carousel/dist/carousel.css';
import { Carousel, Slide, Pagination} from 'vue3-carousel';
import axios from 'axios';
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
            700: {
                itemsToShow: 3.5,
                snapAlign: 'center',
            },
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
      initialized: false,
    cards:[]
    }
  },created(){
        axios.get("https://api.trello.com/1/lists/628621c66fc12b020d3a62e0/cards?attachments=true")
        .then(response => {
            response.data.forEach(element => {
              this.cards.push({text: element.name, image: element.attachments[0].url, page_url :element.desc})
            });
        }).finally(()=>{
          this.initialized = true
        })
    }
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