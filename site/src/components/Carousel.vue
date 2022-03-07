<template>
    <carousel :settings="settings" :breakpoints="breakpoints">
        <slide v-for="slide in 5" :key="slide">
            <div class="carousel__item">
                <!--<img class="carousel_photo" src="https://us.123rf.com/450wm/tupungato/tupungato1611/tupungato161100074/66488989-science-doodle-background-seamless-vector-texture-with-physics-concepts-.jpg?ver=6">
                -->{{slide}}
            </div>
        </slide>

        <template #addons>
            <navigation />
            <pagination />
        </template>
    </carousel>
</template>

<script>
import 'vue3-carousel/dist/carousel.css';
import { Carousel, Slide, Pagination, Navigation } from 'vue3-carousel';

export default {
  name: "carousel-component",
  props:{
      settings:Object,
      breakpoints:Object
  },
  components: {
    Carousel,
    Slide,
    Pagination,
    Navigation,
  },
  data() {
    return {
        payload:[
            {name: "André Pereira",image: 'https://avatars.githubusercontent.com/u/54562621?v=4', linkedin_url: 'https://www.linkedin.com/in/andr%C3%A9-pereira-680209194/'},
            {name: "Vasco Rodrigues",image: 'https://avatars.githubusercontent.com/u/34923176?v=4', linkedin_url: 'https://www.linkedin.com/in/andr%C3%A9-pereira-680209194/'},
            {name: "António Coimbra",image: 'https://avatars.githubusercontent.com/u/65049521?v=4', linkedin_url: 'https://www.linkedin.com/in/andr%C3%A9-pereira-680209194/'},
            {name: "Gonçalo Midões",image: 'https://avatars.githubusercontent.com/u/69457730?v=4', linkedin_url: 'https://www.linkedin.com/in/goncalo-midoes/'},
        ]
    }
  }
};
</script>

<style>
.carousel__item {
  min-height: 200px;
  width: 100%;
  background-color: #009DE0;
  color:  var(--vc-clr-white);
  font-size: 20px;
  border-radius: 8px;
  display: flex;
  justify-content: center;
  align-items: center;
}

.carousel__pagination-button--active {
    background-color: #009DE0;
}

.carousel_photo {
  width: 5vw;
  height: 5vw;
}

.carousel__slide {
  padding: 10px;
}

.carousel__prev,
.carousel__next {
  box-sizing: content-box;
  border: 5px solid white;
  background-color: #009DE0;
}
</style>