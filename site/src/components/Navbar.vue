<template>
  <div class="navbar" id="navbar">
    <div class="navbar-content">
      <!-- NEECIST Logo -->
      <div class="navbar-logo-wrapper">
        <router-link router-link :to="{ name: 'Home' }">
          <img class="navbar-left-logo" :src="navbar_logo_link" />
          <img class="navbar-left-logo-mobile" :src="navbar_mobile_logo_link" />
        </router-link>
      </div>
      
      <!-- Rest of Navbar Entries -->
      <div class="navbar-links">
        <router-link router-link :to="{ name: 'Team' }">
          <div class="navbar-title">Equipa</div>
        </router-link>       
        <router-link router-link :to="{ name: 'Projects' }">
          <div class="navbar-title">Projetos</div>
        </router-link>
        <router-link router-link :to="{ name: 'NEECATHON' }">
          <div class="navbar-title">NEECATHON</div>
        </router-link>
      </div>
    </div> <!-- /.navbar-content -->

    <!-- Old NEEC Room status -->
    <!--
    <div class="pagesBox">
      <div class="sedeStatus">
        A Sede do NEEC está <div class="sedeBtnContainer">
          <span  class="sedeBtn" v-bind:style= "boolean_sede_state ? {backgroundColor: `green`} : {backgroundColor: `red`}"/>
        </div>
      </div>
    </div>
    -->

    <div id="menuToggle">
      <input type="checkbox" :checked="show_menu" v-on:click="show_menu = !show_menu" />
      <span></span>
      <span></span>
      <span></span>

      <ul id="menu">
        <li v-on:click="redirect('Home')">Home</li>
        <li v-on:click="redirect('Oportunities')">Oportunities</li>
        <li v-on:click="redirect('Team')">Equipa</li>
        <!-- <li v-on:click="redirect('Projects')">Projetos</li> -->

      </ul>
    </div>
  </div>
  
</template>

<script>
import neec_logo from "../../static/partner-logos/neec_logo.png"
import neec_logo_mobile from "../../static/neec.svg"
import DataService from "../services/DataService";

export default {
  name: "navbar-component",
  data() {
    return {
      show_menu: false,
      show_registrations: false,
      show_schedule: false,
      navbar_logo_link: neec_logo,
      sede_state: [],
      boolean_sede_state: false,
      navbar_mobile_logo_link: neec_logo_mobile
    };
  },
  methods: {
    onDataChange(items) {
      //let payload = [];
      // items.val().forEach((item) => {
      //   let key = item.key;
      //   let data = item.val();
      //   payload.push({
      //     key: key,
      //     status: data,
      //   });
      // });
      // console.log(items.val());
      // this.sede_state = payload;
      this.boolean_sede_state = items.val()['aberta'] === 'True';
    },
    redirect(page) {
      this.show_menu = false;
      this.$router.push({ name: page });
    },
    handleScroll() {
      if (window.scrollY > 595) {
        document.getElementById("navbar").classList.add("dark");
        document.getElementById("menu").classList.add("dark");
      } else {
        document.getElementById("navbar").classList.remove("dark");
        document.getElementById("menu").classList.remove("dark");
      }
    }
  },
  mounted(){
    window.addEventListener('scroll', this.handleScroll);
    DataService.getAll().on("value", this.onDataChange);
  },
  beforeUnmount() {
    window.removeEventListener('scroll', this.handleScroll);
    DataService.getAll().off("value", this.onDataChange);
  }
};
</script>

<style>
#navbar.dark{
  background-color: #252525;
  color:#FFF4E8;
}
#menu.dark{
  background-color: #252525;
  color:#FFF4E8;
}
#navbar.dark > .nameState {
  color:#FFF4E8;
}
#navbar.dark .navbar-title {
  color: #FFF4E8;
}


a, a:-webkit-any-link {
text-decoration: none;
}

.navbar {
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  /* make it span exactly the viewport width */
  width: 100vw;
  background-color: #FFF4E8;
  z-index: 1000;
}
.navbar-left-logo {
  width: 160px;
}
.navbar-left-logo-mobile {
  display: none;
}

.navbar-content {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 1vh 2vw;
}

.pagesBox {
  display: flex;
  align-items: center;
  justify-content: flex-end;
}

.sedeStatus{
 font-weight: bold;
 margin-right: 3vw;
 font-size: larger;
 display: flex;
 align-items: center;
}
.sedeStatus small{
  display: flex;
  justify-content: center;
  align-items: center;
}
.sedeBtnContainer{
  padding-left: 5px;
  line-height: 0;
}
.platform-button {
  margin-top: 15px;
  height: 30px;
  text-align: center;
  /*float: left;*/
  margin-left: 20px;
  width: 170px;
  border-radius: 10px;
  background: #fff;
  color: #27ade4;
  font-weight: bold;
  font-size: 17px;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  padding-top: 8px;
  border: 2px solid #27ade4;
  transition: all 0.2s ease-in-out;
  display: inline-block;
}
.platform-button:hover {
  box-shadow: 0 2px 10px 0 rgba(0, 0, 0, 0.1);
  transform: scale(1.03);
  cursor: pointer;
}
.platform-button-menu {
  margin-top: 15px;
  height: 30px;
  text-align: center;
  width: 170px;
  border-radius: 10px;
  background: #fff;
  color: #27ade4;
  font-weight: bold;
  font-size: 17px;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  padding-top: 8px;
  border: 2px solid #27ade4;
  transition: all 0.2s ease-in-out;
  display: none;
}
.brain-msg {
  display: inline-block;
  margin-left: 20px;
  margin-top: 28px;
  font-size: 14px;
  /*float: left;*/
}
.join-quote,
.register-button {
  display: inline-block;
}

.navbar-logo-wrapper {
  flex-shrink: 0;
}

.navbar-links {
  display: flex;
  align-items: center;
  gap: 2vw;
}

.navbar-title {
  color:   #252525;
  font-family: 'Montserrat', sans-serif;
  -o-transition: 0.2s;
  -ms-transition: 0.2s;
  -moz-transition: 0.2s;
  -webkit-transition: 0.2s;
  transition: 0.2s;
  font-size: 19px;
  padding-inline: 3vw 1vw;
  font-weight: bold;
}
.navbar-title:hover {
  color: rgb(55, 121, 184);
  transform: scale(1.1);
}

body {
  margin: 0;
  padding: 0;
  background: #232323;
  color: #cdcdcd;
  font-family: 'Roboto', sans-serif;
}

#menuToggle {
  display: none;
  z-index: 1;
  -webkit-user-select: none;
  user-select: none;
}
#menuToggle input {
  display: block;
  width: 10vw;
  height: 100%;
  position: absolute;
  right: 0;
  top: 0;
  cursor: pointer;
  opacity: 0;
  z-index: 2;
  -webkit-touch-callout: none;
}
#menuToggle span {
  display: block;
  width: 33px;
  height: 4px;
  margin-bottom: 5px;
  position: relative;
  background: #5ea2e2;
  border-radius: 3px;
  z-index: 1;
  transform-origin: 4px 0px;
  transition: transform 0.5s cubic-bezier(0.77, 0.2, 0.05, 1),
    background 0.5s cubic-bezier(0.77, 0.2, 0.05, 1), opacity 0.55s ease;
}
#menuToggle span:first-child {
  transform-origin: 0% 0%;
}
#menuToggle span:nth-last-child(2) {
  transform-origin: 0% 100%;
}
#menuToggle input:checked ~ span {
  opacity: 1;
  transform: rotate(45deg) translate(-2px, -1px);
  background: #232323;
}
#menuToggle input:checked ~ span:nth-last-child(3) {
  opacity: 0;
  transform: rotate(0deg) scale(0.2, 0.2);
}
#menuToggle input:checked ~ span:nth-last-child(2) {
  transform: rotate(-45deg) translate(0, -1px);
}

#menu {
  margin: 0;
  right: 0;
  top: 100%;
  position: absolute;
  padding: 5vh 12vw;
  background: #ffffff;
  list-style-type: none;
  -webkit-font-smoothing: antialiased;
  box-shadow: none;
  border-radius: 0 0 0 10px;
  transform-origin: 0% 0%;
  transform: translate(0px, -400px);
  transition: transform 0.3s;
}
#menu li {
  padding: 20px 0;
  font-size: 22px;
}
#menuToggle input:checked ~ ul {
  transform: none;
  box-shadow: 0 200px 300px 0 rgb(0 0 0 / 30%);
}
@media only screen and (max-width: 1250px) {
  .join-quote {
    display: none;
  }
  .register-button {
    margin-top: 24px;
  }
}
/* On screens that are 600px wide*/
@media only screen and (max-width: 1080px) {
  .navbar {
    height: 70px;
  }
  .navbar-left-logo {
    display: none;
  }
  .navbar-left-logo-mobile {
    display: block;
    width: 50px;
    margin-left: 20px;
    margin-top: 10px;
    float: left;
  }

  .sedeStatus{
    font-size: large;
  }

  .navbar-title{
    display: none;
  }

  #menuToggle {
    display: block;
    width: 10vw;
  }
  .register-button {
    margin-top: 24px;
    font-size: 14px;
    letter-spacing: 0.8px;
  }

  .platform-button {
    margin-top: 15px;
    margin-left: 30px;
  }
  .team-app{
      padding: 90px 11px 200px;
  }
}
@media only screen and (max-width: 760px) {
  .brain-msg {
    display: none;
  }
}
@media only screen and (max-width: 400px) {
  .platform-button {
    display: none;
  }
  .platform-button-menu {
    display: inline-block;
  }
}
@media only screen and (max-width: 350px) {
  .register-button {
    margin-top: 30px;
  }
}
.sedeBtn{
  animation: blinker 2s linear infinite;
  width: 16px;
  height: 16px;
  display: inline-block;
  border-radius: 100%;
}

@keyframes blinker {
  50% {
    opacity: 0.6;
  }
}
</style>
