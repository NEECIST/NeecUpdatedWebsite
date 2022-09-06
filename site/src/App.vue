<template>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@400;700&display=swap" rel="stylesheet">
  <div id="page">
    <Navbar/>
    <router-view/>
    <Footer />
  </div>
</template>

<script>
import Navbar from './components/Navbar'
import Footer from './components/Footer'
import AOS from 'aos'
import 'aos/dist/aos.css'

export default {
  name: 'App',
  components: {
    Navbar,
    Footer,
  },mounted(){
      AOS.init({
            once: true,
            duration: 500,
      });
  }
}
</script>

<style>

#page {
  font-family: 'Roboto', sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  width: 100%;
  background-color: white;
  min-height:100vh;
  position:relative;
}
body {
  margin: 0;
  height: 100%;
}
html{
    height:100%;
}
</style>
