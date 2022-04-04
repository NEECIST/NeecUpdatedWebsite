<template>
    <div class="card">
        <div class="circle" :style="cssCircle"></div>
        <div class="content" :style="cssContent">
            <h2>{{title}}</h2>
            <p>{{description}}</p>
            <a v-if="link" :href="link">{{link_message}}</a>
            <a v-if="redirect_function" v-on:click="redirect(redirect_function)">{{link_message}}</a>
        </div>
        <img :src="image" :style="cssImage"/>
    </div>
</template>

<script>
export default {
  name: "responsive-card-component",
  props:{
    image:{
        type:String,
        default: null
    },
    link:{
        type:String,
        default: null
    },
    link_message:{
        type:String,
        default: null
    },
    title:{
        type:String,
        default: null
    },
    description:{
        type:String,
        default: null
    },
    main_color:{
        type:String,
        default: null
    },
    secondary_color:{
        type:String,
        default: null
    },
    height:{
        type:Number,
        default: 50
    },
    top:{
        type:Number,
        default: 50
    },
    left:{
        type:Number,
        default: 50
    },
    image_height:{
        type:Number,
        default: 300
    },
    zoom_height:{
        type:Number,
        default: 500
    },
    zoom_position:{
        type:Number,
        default: 72
    },
    top_padding:{
        type:Number,
        default: 20
    },
    right_padding:{
        type:Number,
        default: 20
    },
    bottom_padding:{
        type:Number,
        default: 20
    },
    left_padding:{
        type:Number,
        default: 40
    },
    redirect_function:{
        default: null
    },
    top_flatted_screen:{
        type:Number,
        default: null
    },
  },
  data(){
      return{
      }
  },
  methods : {
    redirect(page) {
      this.show_menu = false;
      this.$router.push({ name: page });
    }
  },
  computed: {
    cssCircle() {
      return {
        '--main-color': this.main_color,
        '--secondary-color': this.secondary_color,
      }
    },
    cssImage() {
      return {
        '--top': this.top + '%',
        '--top-flatted-screen': this.top_flatted_screen + '%',
        '--left': this.left + '%',
        '--image-height': this.image_height + 'px',
        '--zoom-height': this.zoom_height + 'px',
        '--zoom-position': this.zoom_position + '%',
      }
    },
    cssContent() {
      return {
        '--description-padding': this.top_padding + 'px ' + this.right_padding + 'px ' + this.bottom_padding + 'px ' + this.left_padding + 'px',
      }
    }
  }
}
</script>

<style scoped>
*{
    margin:0;
    padding:0;
    box-sizing: border-box;
    font-family: 'Poppins', sans-serif;
}
body{
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
}
.card{
    position:relative;
    width: 600px;
    height: 350px;
    border-radius: 20px;
    display: flex;
    align-items: center;
    transition: 0.5s;
}
.card .circle{
    position:absolute;
    top: 0;
    left: 0;
    width:100%;
    height:100%;
    border-radius: 20px;
    overflow: hidden;
}
.card .circle::before{
    content: '';
    position:absolute;
    top: 0;
    left: 0;
    width:100%;
    height:100%;
    background: var(--main-color);
    clip-path: circle(120px at center);
    transition: 0.5s;
}
.card:hover .circle:before{
    background: var(--secondary-color);
    clip-path: circle(400px at center);
}
.card img{
    position:absolute;
    top: var(--top);
    left: var(--left);
    transform: translate(-50%,-50%);
    height:var(--image-height);
    pointer-events: none;
    transition: 0.5s;
}
.card:hover img{
    left: var(--zoom-position);
    height:var(--zoom-height);
}
.card .content{
    position: relative;
    padding: var(--description-padding);
    transition: 0.5s;
    opacity: 0;
    visibility: hidden;
}
.card:hover .content{
    left:0;
    opacity: 1;
    visibility: visible;
}
.card .content h2
{
    color:white;
    text-transform: uppercase;
    font-size: 2em;
    line-height: 1em;
    margin-bottom: 5px;
}
.card .content p
{
    color:white;
}
.card .content a
{
    position:relative;
    color:white;
    padding: 10px 20px;
    border-radius: 10px;
    background:white;
    color: black;
    margin-top: 10px;
    display:inline-block;
    text-decoration: none;
    font-weight: 700;
}

@media(max-width: 990px)
{
    .card
    {
        width: auto;
        max-width: 350px;
        align-items: flex-start;
        margin: 10px;
    }
    .card:hover
    {
        height: calc(var(--image-height)*0.2);
    }
    .card .content
    {
        width:100%;
        left:0;
        padding:30px;
    }
    .card img
    {
        left: 50%;
        height: calc(var(--image-height)*0.8);
    }
    .card:hover img
    {
        top: var(--top-flatted-screen);
        left: calc(var(--zoom-position)*0.6);
        height: calc(var(--zoom-height)*0.6);
    }
}
@media(max-width: 420px)
{
    .card .content
    {
        padding:20px;
    }
}
</style>