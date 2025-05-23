<template>
  <div>
    <!-- Full contact section (slides up only at page‐bottom) -->
    <section
      id="contact"
      class="contact-section"
      :class="{ show: isAtBottom }"
    >
      <div class="container">
        <div class="col-md-4">
          <!-- your location/address… -->
        </div>
        <div class="col-md-4">
          <!-- <h2>Redes Sociais</h2>  Remove this entire column -->
          <!-- …and its icons––we’ll pin them separately. -->
        </div>
        <div class="col-md-4">
          <!-- your phone/email… -->
        </div>
      </div>
    </section>

    <!-- → NEW: Always-fixed social icons bar -->
    <transition name="fade">
      <div 
        class="scrollable-footer"
        v-show="footerVisible && !isAtBottom"
      >
        <div class="socials-footer">
          <a href="https://www.facebook.com/NEECIST/" target="_blank">
            <i class="fa-brands fa-facebook icon"></i>
          </a>
          <a href="https://github.com/NEECIST" target="_blank">
            <i class="fa-brands fa-github icon"></i>
          </a>
          <a href="https://www.linkedin.com/company/2977028/" target="_blank">
            <i class="fa-brands fa-linkedin icon"></i>
          </a>
          <a href="https://www.instagram.com/neecist/" target="_blank">
            <i class="fa-brands fa-instagram icon"></i>
          </a>
          <a href="https://www.youtube.com/user/NEECIST" target="_blank">
            <i class="fa-brands fa-youtube icon"></i>
          </a>
          <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
            <i class="fa-brands fa-spotify icon"></i>
          </a>
        </div>
      </div>
    </transition>

    <!-- Sticky bottom-bar (as before) -->
    <div 
      class="socials"
    >
      <a href="https://www.facebook.com/NEECIST/" target="_blank">
        <i class="fa-brands fa-facebook icon"></i>
      </a>
      <a href="https://github.com/NEECIST" target="_blank">
        <i class="fa-brands fa-github icon"></i>
      </a>
      <a href="https://www.linkedin.com/company/2977028/" target="_blank">
        <i class="fa-brands fa-linkedin icon"></i>
      </a>
      <a href="https://www.instagram.com/neecist/" target="_blank">
        <i class="fa-brands fa-instagram icon"></i>
      </a>
      <a href="https://www.youtube.com/user/NEECIST" target="_blank">
        <i class="fa-brands fa-youtube icon"></i>
      </a>
      <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
        <i class="fa-brands fa-spotify icon"></i>
      </a>
    </div>
    <div class="bottom-bar" :class="{ show: footerVisible }">
      <div id="copyright">
        © 2022 Núcleo de Estudantes de Eletrotécnica e de Computadores do IST
      </div>
    </div>
  </div>
</template>


<script>
export default {
  name: "footer-component",
  data() {
    return {
      footerVisible: false,
      isAtBottom: false,
    };
  },
  mounted() {
    window.addEventListener("scroll", this.handleScroll);
    this.handleScroll(); // initialize on load
  },
  beforeUnmount() {
    window.removeEventListener("scroll", this.handleScroll);
  },
  methods: {
    handleScroll() {
      const scrollY = window.scrollY;
      const winH = window.innerHeight;
      const docH = document.documentElement.scrollHeight;

      this.footerVisible = scrollY > 100;
      this.isAtBottom = scrollY + winH >= docH - 10;
    },
  },
};
</script>

<style scoped>
  /* pinned absolutely just above the bottom-bar */
  /* default (mid‐page) */
  .scrollable-footer {
    position: fixed;
    bottom: 0;
    left: 0;
    right: 0;
    display: flex;
    gap: 1rem;
    padding: 0.5rem 0 0.5rem 1rem;
    background: rgba(37,37,37,0.8);
    transition: background 0.3s ease, transform 0.3s ease;
    z-index: 1001;
  }

  /* bottom‐of‐page variant */
  .scrollable-footer--bottom {
    background: rgba(55,121,184,0.9);
    position: absolute;
    transform: scale(1.1);
  }

  /* social icons */
  .socials-footer {
    display: flex;
    justify-content: center;
    gap: 1rem;
    padding: 0.5rem 0;
    left: 1vm;
  }
  .socials-footer .icon {
    font-size: 1.5rem;
    color: #fff4e8;
  }
  .socials-footer .icon:hover {
    color: #009de0;
  }

  .site-footer {
    background: #252525;
    color: #fff4e8;
  }

  /* Fade in/out over 0.3s */
  .fade-enter-active,
  .fade-leave-active {
    transition: opacity 0.3s ease;
  }
  .fade-enter-from,
  .fade-leave-to {
    opacity: 0;
  }
  .fade-enter-to,
  .fade-leave-from {
    opacity: 1;
  }

  /* Top section */
  .footer-top {
    padding: 2rem;
  }
  .footer-top .container {
    display: flex;
  }
  .footer-top .col-md-4 {
    flex: 1;
    padding: 0 1rem;
  }

  /* Social icons */
  .socials {
    display: flex;
    gap: 0.5rem;
  }
  .icon { font-size: 1.5rem; }

  /* Bottom bar */
  .footer-bottom {
    padding: 1rem;
    text-align: center;
    background: #1a1a1a;
    font-size: 0.9rem;
  }

  
  .bottom-bar {
    margin-top: 10px;
    width: 100%;
    height: 30px;
    background-color: #252525;
    color: #FFF4E8;
    position: relative;
    overflow: hidden;
    bottom: 0;
  }

  /* Make sure links are visible */
  a { color: #fff4e8; }
  a:hover { color: #009de0; }
</style>




<!--
<template>
  <div class="contacts-comp" :class="footerState">
    <section id="contact" class="section-bg wow fadeInUp">
      <div class="container">
        <div class="row">
          <div class="col-md-4">
            <div class="location-adress">
              <p><i class="fa-solid fa-location-dot" :style="{marginRight: '4px' }"></i> Instituto Superior Técnico - Av. Rovisco Pais, 1049-001 Lisboa</p>
              <p>
                <i class="fa-solid fa-building-flag" :style="{marginRight: '4px' }"></i>
                <a style="color: white" href="https://neecist.org/acessos_sede">Sede do NEEC - Pavilhão de Electricidade, Piso 4, Sala 4i.13</a>
              </p>
              <p><i class="fa-solid fa-flask" :style="{marginRight: '4px' }"></i> NEECLab - Pavilhão de Electricidade, Piso 1 (Junto à receção da SCDEEC)</p>
            </div>
          </div>
          <div class="col-md-4">
            <div class="socials">
              <h2>Redes Sociais</h2>
              <a href="https://www.facebook.com/NEECIST/" target="_blank">
                <i class="fa-brands fa-facebook icon" :style="{ color: '#FFF4E8' }"></i>
              </a>
              <a href="https://github.com/NEECIST" target="_blank">
                <i class="fa-brands fa-github icon" :style="{ color: '#FFF4E8' }"></i>
              </a>
              <a href="https://www.linkedin.com/company/2977028/" target="_blank">
                <i class="fa-brands fa-linkedin icon" :style="{ color: '#FFF4E8' }"></i>
              </a>
              <a href="https://www.instagram.com/neecist/" target="_blank">
                <i class="fa-brands fa-instagram icon" :style="{ color: '#FFF4E8' }"></i>
              </a>
              <a href="https://www.youtube.com/user/NEECIST" target="_blank">
                <i class="fa-brands fa-youtube icon" :style="{ color: '#FFF4E8' }"></i>
              </a>
              <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
                <i class="fa-brands fa-spotify icon" :style="{ color: '#FFF4E8' }"></i>
              </a>
            </div>
          </div>
          <div class="col-md-4">
            <div class="contact-adress">
              <p><i class="fa-solid fa-phone" :style="{marginRight: '6px' }"></i> <a class="contact-address-text" href="tel:(+351) 218 419 056">(+351) 218 417 745</a></p>
              <p><i class="fa-solid fa-envelope" :style="{marginRight: '6px' }"></i> <a class="contact-address-text" href="mailto:contacto@neecist.org">contacto@neecist.org</a></p>
            </div>
          </div>
        </div>
      </div>
    </section>

    <div class="bottom-bar">
      <div id="copyright">Copyright © 2022 - Núcleo de Estudantes de Eletrotécnica e de Computadores do Instituto Superior Técnico</div>
    </div>
  </div>
</template>

<script>
export default {
  name: "footer-component",
  data() {
    return {
      footerVisible: false,
      isAtBottom: false
    };
  },

  computed: {
    footerState() {
      return {
        'footer-hidden': !this.footerVisible && !this.isAtBottom,
        'footer-visible': this.footerVisible && !this.isAtBottom,
        'footer-expanded': this.isAtBottom,
      };
    },
  },
  mounted() {
    window.addEventListener("scroll", this.handleScroll);
    this.handleScroll();  // Initial check
  },
  beforeUnmount() {
    window.removeEventListener("scroll", this.handleScroll);
  },
  methods: {
    handleScroll() {
      const scrollY = window.scrollY;
      const windowHeight = window.innerHeight;
      const fullHeight = document.body.scrollHeight;

      // Show when scrolling down a bit
      this.footerVisible = scrollY > 100;

      // Expand when near bottom
      this.isAtBottom = (scrollY + windowHeight + 50) >= fullHeight;
    },
  },
};
</script>

<style>
body {
  padding-bottom: 120px; /* Adjust based on footer height */
}
.socials {
  text-align: center;
  font-size: 30px;
}
.socials h2 {
  font-size: 20px;
  margin-bottom: 10px;
  font-weight: bold;
  text-transform: uppercase;
  color: #FFF4E8;
}
.icon {
  color: #FFF4E8;
  margin: 5px;
}

#source-code img {
  height: 20px;
  width: 30px;
  opacity: 0.85;
  transition: all 0.3s;
}
#source-code img:hover {
  opacity: 1;
  -webkit-filter: grayscale(0%);
  filter: grayscale(0%);
}
.contacts-comp {
  transition: transform 0.5s ease, opacity 0.5s ease;
  position: fixed;
  width: 100%;
  bottom: 0;
  background-color: #252525;
  text-align: left;
  color: #FFF4E8;
  transition: all 0.5s ease;
  overflow: hidden;
  z-index: 10;
}
/* Hidden by default */
.footer-hidden {
  transform: translateY(100%);
  height: 0;
  opacity: 0;
  pointer-events: none;
}

/* Compact footer while scrolling */
.footer-visible {
  transform: translateY(0%);
  height: 120px;
  opacity: 1;
  background-color: #252525;
}

/* Expanded footer at bottom */
.footer-expanded {
  transform: translateY(0%);
  height: auto;
  background-color: #252525;
  opacity: 1;
}
.bottom-bar {
  margin-top: 10px;
  width: 100%;
  height: 30px;
  background-color: #252525;
  color: #FFF4E8;
  position: relative;
  overflow: hidden;
  bottom: 0;
}
#copyright {
  padding-left: 10px;
  padding-bottom: 5px;
  font-size: 13px;
  float: left;
  font-family: "Roboto", sans-serif;
}
#source-code {
  float: right;
  font-family: "Roboto", sans-serif;
  padding-right: 10px;
  padding-bottom: 5px;
  font-size: 13px;
}

.flexbox-imgs {
  display: -webkit-box; /* iOS 6-, Safari 3.1-6, BB7 */
  display: -ms-flexbox; /* IE 10 */
  display: -webkit-flex; /* Safari 6.1+. iOS 7.1+, BB10 */
  display: flex; /*Firefox, Chrome, Opera */

  flex-wrap: wrap;
  justify-content: center;
  align-items: center;
  flex-direction: row;
}

.row {
  display: flex;
  align-items: center;
  justify-content: center;
  height: 150px;
}
.flexbox-imgs img {
  justify-content: center;
  max-height: 100px;
  max-width: 150px;
  margin: 5px 12px;
  padding-left: 30px;
  opacity: 0.85;
  transition: all 0.3s;
}
.flexbox-imgs img:hover {
  opacity: 1;
  -webkit-filter: grayscale(0%);
  filter: grayscale(0%);
}
.credits a {
  display: block;
  text-align: center;
}
@media screen and (max-width: 800px) {
  .flexbox-imgs img {
    max-width: 125px;
    max-height: 88px;
    margin: 5px 8px;
    padding-left: 10px;
  }
}
@media screen and (max-width: 560px) {
  .flexbox-imgs img {
    max-width: 85px;
    max-height: 60px;
    margin: 3px 5px;
  }
  .copyright {
    text-align: center;
    font-size: 8px;
    width: 80%;
    padding-left: 0px;
    padding-bottom: 0px;
  }
  .source-code {
    text-align: center;
  }
  .bottom-bar {
    text-align: center;
    height: 50px;
  }
}
.section-with-bg {
  background-color: #f6f7fd;
}

.col-md-4 {
  width: 33%;
  display: inline-block;
}

.location-adress {
  float: left;
  font-size: 16px;
  font-family: "Roboto";
  color: #FFF4E8;
  padding: 10px;
  padding-left: 10px;
}
.contact-adress {
  float: right;
  font-size: 16px;
  font-family: "Roboto";
  color: #FFF4E8;
  padding: 20px;
}
.contact-address-text {
  color: #FFF4E8;
}
.contact-address-text:hover {
  color: #009de0;
}
@media screen and (max-width: 560px) {
  .col-md-4 {
    width: 80%;
  }
}
</style>
-->