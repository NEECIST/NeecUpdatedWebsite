<template>
    <carousel :settings="settings" :breakpoints="breakpoints">
        <slide v-for="slide in payload" :key="slide">
          <a v-if="slide.page_url" class="carousel__item" :href="slide.page_url" target="_blank">
            <div v-if="slide.local" class="carousel__item" :style="{ backgroundImage: `url(${require('../assets/' + slide.image)})`,backgroundColor: slide.backcolor, backgroundSize: slide.backsize,backgroundPosition:slide.backposition,backgroundRepeat:slide.backrepeat }">
                <div v-if="slide.main_text" class="carousel__main__text" :style="{color: slide.maincolor ,fontFamily: slide.mainfont, fontSize: slide.mainfontSize + 'px', marginLeft: slide.mainleftmargin + 'px', marginBottom: slide.mainbottommargin + 'px', textShadow: slide.mainshadow}">
                  {{slide.main_text}}
                  <div v-if="slide.secondary_text" class="carousel__secondary__text" :style="{color: slide.secondarycolor ,fontFamily: slide.secondaryfont, fontSize: slide.secondaryfontSize + 'px', marginLeft: slide.secondaryleftmargin + 'px', marginBottom: slide.secondarybottommargin + 'px', textShadow: slide.secondaryshadow}">
                    {{slide.secondary_text}}
                  </div>
                </div>
            </div>
            <div v-else class="carousel__item" :style="{'background-image': 'url('+slide.image+')',backgroundColor: slide.backcolor, backgroundSize: slide.backsize,backgroundPosition:slide.backposition,backgroundRepeat:slide.backrepeat }">
                <div v-if="slide.main_text" class="carousel__main__text" :style="{color: slide.maincolor ,fontFamily: slide.mainfont, fontSize: slide.mainfontSize + 'px', marginLeft: slide.mainleftmargin + 'px', marginBottom: slide.mainbottommargin + 'px', textShadow: slide.mainshadow}">
                  {{slide.main_text}}
                  <div v-if="slide.secondary_text" class="carousel__secondary__text" :style="{color: slide.secondarycolor ,fontFamily: slide.secondaryfont, fontSize: slide.secondaryfontSize + 'px', marginLeft: slide.secondaryleftmargin + 'px', marginBottom: slide.secondarybottommargin + 'px', textShadow: slide.secondaryshadow}">
                    {{slide.secondary_text}}
                  </div>
                </div>
            </div>
          </a>
          <div class="carousel__item" v-else>
            <div v-if="slide.local" class="carousel__item" :style="{ backgroundImage: `url(${require('../assets/' + slide.image)})`,backgroundColor: slide.backcolor, backgroundSize: slide.backsize,backgroundPosition:slide.backposition,backgroundRepeat:slide.backrepeat  }">
                <div v-if="slide.main_text" class="carousel__main__text" :style="{color: slide.maincolor ,fontFamily: slide.mainfont, fontSize: slide.mainfontSize + 'px', marginLeft: slide.mainleftmargin + 'px', marginBottom: slide.mainbottommargin + 'px', textShadow: slide.mainshadow}">
                  {{slide.main_text}}
                  <div v-if="slide.secondary_text" class="carousel__secondary__text" :style="{color: slide.secondarycolor ,fontFamily: slide.secondaryfont, fontSize: slide.secondaryfontSize + 'px', marginLeft: slide.secondaryleftmargin + 'px', marginBottom: slide.secondarybottommargin + 'px', textShadow: slide.secondaryshadow}">
                    {{slide.secondary_text}}
                  </div>
                </div>
            </div>
            <div v-else class="carousel__item" :style="{'background-image': 'url('+slide.image+')',backgroundColor: slide.backcolor, backgroundSize: slide.backsize,backgroundPosition:slide.backposition,backgroundRepeat:slide.backrepeat }">
                <div v-if="slide.main_text" class="carousel__main__text" :style="{color: slide.maincolor ,fontFamily: slide.mainfont, fontSize: slide.mainfontSize + 'px', marginLeft: slide.mainleftmargin + 'px', marginBottom: slide.mainbottommargin + 'px', textShadow: slide.mainshadow}">
                  {{slide.main_text}}
                  <div v-if="slide.secondary_text" class="carousel__secondary__text" :style="{color: slide.secondarycolor ,fontFamily: slide.secondaryfont, fontSize: slide.secondaryfontSize + 'px', marginLeft: slide.secondaryleftmargin + 'px', marginBottom: slide.secondarybottommargin + 'px', textShadow: slide.secondaryshadow}">
                    {{slide.secondary_text}}
                  </div>
                </div>
            </div>
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
      settings:{
        type: Object,
        default: () => ({
            itemsToShow:1,
            itemsToScroll:1,
            wrapAround:true,
            snapAlign:'center',
            transition:300,
            autoplay:5000,
            breakpoints:null,
            modelValue:0,
            mouseDrag:true,
            touchDrag:true,
            pauseAutoplayOnHover:true,
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
      },
      payload:{
        type:Array,
        default: null
      }
  },
  components: {
    Carousel,
    Slide,
    Pagination,
    Navigation,
  },
  data() {
    return {
      /*txtColor:"#0099CC",
      height: -200,
      font: "Times New Roman"*/
    }
  },
  mounted: function(){
    //console.log(this.payload)
  },
  computed: {
    /*cssTextVars() {
      return {
        '--text-color': this.txtColor,
        '--height': this.height + 'px',
        '--font':this.font
      }
    }*/
  }
};
</script>

<style>

.carousel__item {
  min-height: 300px;
  min-width: 100%;
  background-color: #009DE0;
  color:  var(--vc-clr-white);
  font-size: 20px;
  border-radius: 8px;
  display: flex;
  justify-content: center;
  align-items: center;
  background-size: cover;
  background-repeat: no-repeat;
  background-position:center;
}

.carousel__main__text {
  font-size: 18px;
  margin-bottom: -180px;
  margin-left: 0px;
  text-transform: uppercase;
  color: black;
  text-align: center;
  text-shadow: none;
}

.carousel__secondary__text {
  font-size: 13px;
  margin-bottom: -240px;
  margin-left: 0px;
  color: black;
  text-align: center;
  position:relative;
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