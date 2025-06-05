<!-- Note that maybe the fixed bar should maybe only be used in the home page -->
<!-- Maybe have it but always showing instead of not showing in the beggining -->
<template>
  <div>
    <!-- Always-fixed bar -->
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

        <div class="copyright-footer" id="copyright">
          © NEECIST 2025
        </div>
      </div>
    </transition>

    <!-- Sticky bottom-bar -->
    <div>
      <section id="contact">
        <div class="footer-top container">
          <div class="row">
            <div class="col-md-3">
              <div class="location-adress">
                <p>
                  <i class="fa-solid fa-location-dot" :style="{marginRight: '4px' }"></i>
                  Instituto Superior Técnico - Av. Rovisco Pais, 1049-001 Lisboa
                </p>
                <p>
                  <i class="fa-solid fa-building-flag" :style="{marginRight: '4px' }"></i>
                  <a style="color: #252525" href="https://neecist.org/acessos_sede">Sede do NEEC - Pavilhão de Electricidade, Piso 4, Sala 4i.13</a>
                </p>
                <p>
                  <i class="fa-solid fa-flask" :style="{marginRight: '4px' }"></i>
                  NEECLab - Pavilhão de Electricidade, Piso 1 (Junto à receção da SCDEEC)
                </p>
              </div>
            </div>
            <div class="col-md-3">
              <div class="socials">
                <h2>Redes Sociais</h2>
                <a href="https://www.facebook.com/NEECIST/" target="_blank">
                  <i class="fa-brands fa-facebook icon" :style="{ color: '#252525' }"></i>
                </a>
                <a href="https://github.com/NEECIST" target="_blank">
                  <i class="fa-brands fa-github icon" :style="{ color: '#252525' }"></i>
                </a>
                <a href="https://www.linkedin.com/company/2977028/" target="_blank">
                  <i class="fa-brands fa-linkedin icon" :style="{ color: '#252525' }"></i>
                </a>
                <a href="https://www.instagram.com/neecist/" target="_blank">
                  <i class="fa-brands fa-instagram icon" :style="{ color: '#252525' }"></i>
                </a>
                <a href="https://www.youtube.com/user/NEECIST" target="_blank">
                  <i class="fa-brands fa-youtube icon" :style="{ color: '#252525' }"></i>
                </a>
                <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
                  <i class="fa-brands fa-spotify icon" :style="{ color: '#252525' }"></i>
                </a>
              </div>
            </div>
            <div class="col-md-3">
              <div class="contact-adress">
                <p>Entra em contacto connosco:</p>
                <p><i class="fa-solid fa-phone" :style="{marginRight: '6px' }"></i> <a class="contact-address-text" href="tel:(+351) 218 419 056">(+351) 218 417 745</a></p>
                <p><i class="fa-solid fa-envelope" :style="{marginRight: '6px' }"></i> <a class="contact-address-text" href="mailto:contacto@neecist.org">contacto@neecist.org</a></p>
              </div>
            </div>
          </div>
        </div>
      </section>

      <div class="bottom-bar">
        <div id="copyright">Copyright © 2025 - Núcleo de Estudantes de Eletrotécnica e de Computadores do Instituto Superior Técnico</div>
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
  watch: {
    $route() {
      this.handleScroll(); // Re-evaluate footer visibility on page change
    }
  },
  methods: {
    handleScroll() {
      // Check if the current page is the home page
      const isHome = this.$route?.path === "/";

      const scrollY = window.scrollY;
      const winH = window.innerHeight;
      const docH = document.documentElement.scrollHeight;

      // Always show footer if not on homepage
      if (!isHome) {
        this.footerVisible = true;
      } else {
        this.footerVisible = scrollY > 100;
      }

      this.isAtBottom = scrollY + winH >= docH - 160;
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
    justify-content: space-between;    /* push left group to left, right group to right */
    align-items: center;               /* vertical centering */
    padding: 0rem 0.5rem 0rem 1rem;
    background: #C5B6A7;
    transition: background 0.3s ease, transform 0.3s ease;
    z-index: 1001;
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
    color: #252525;
  }
  .socials-footer .icon:hover {
    color: #009de0;
  }

  .copyright-footer {
    color: #252525;
    text-decoration: none;
    text-align: left;
    padding: 0.5rem 0;
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
    padding: 0rem;
  }
  .footer-top .container {
    display: flex;
  }
  .footer-top .col-md-4 {
    flex: 1;
    padding: 0 0.5rem;
  }

  
  .bottom-bar {
    text-align: right;
    width: 100%;
    height: auto;
    padding: 0rem 0.5rem 0.5rem 0rem;
    background-color: #C5B6A7;
    color: #252525;
    position: relative;
    overflow: hidden;
    bottom: 0;
    flex-wrap: wrap;
    display: flex;
  }

  /* Make sure links are visible */
  a { color: #FFF4E8; }
  a:hover { color: #009de0; }


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
    color: #252525;
  }
  .icon {
    color: #252525;
    margin: 5px;
  }

  #copyright {
    padding-right: 10px;
    padding-bottom: 5px;
    margin-left: auto;
    font-size: 13px;
    font-family: "Montserrat", sans-serif;
  }


  .row {
    display: flex;
    align-items: center;
    justify-content: center;
    height: 165px;
    background-color: #C5B6A7;
  }

  @media screen and (max-width: 560px) {
    .copyright {
      text-align: center;
      font-size: 8px;
      width: 80%;
      padding-left: 0px;
      padding-bottom: 0px;
    }
    .bottom-bar {
      text-align: center;
      height: 50px;
    }
  }

  .col-md-3 {
    width: 33%;
    display: inline-block;
  }

  .location-adress {
    float: left;
    font-size: 16px;
    font-family: "Montserrat";
    color: #252525;
    padding: 10px;
    padding-left: 10px;
  }
  .contact-adress {
    float: right;
    font-size: 16px;
    font-family: "Montserrat";
    color: #252525;
    padding: 20px;
  }
  .contact-address-text {
    color: #252525;
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