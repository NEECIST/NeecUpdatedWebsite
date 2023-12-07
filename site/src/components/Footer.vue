<template>
  <div class="contacts-comp">
    <section id="contact" class="section-bg wow fadeInUp">
      <div class="container">
        <div class="row">
          <div class="col-md-4">
            <div class="location-adress">
              <p><i class="fa-solid fa-location-dot" :style="{ color: 'white', marginRight: '4px' }"></i> Instituto Superior Técnico - Av. Rovisco Pais, 1049-001 Lisboa</p>
              <p>
                <i class="fa-solid fa-building-flag" :style="{ color: 'white', marginRight: '4px' }"></i>
                <a style="color: white" href="http://localhost:8080/acessos_sede">Sede do NEEC - Pavilhão de Electricidade, Piso 4, Sala 4i.13</a>
              </p>
              <p><i class="fa-solid fa-flask" :style="{ color: 'white', marginRight: '4px' }"></i> NEECLab - Pavilhão de Electricidade, Piso 1 (Junto à receção da SCDEEC)</p>
            </div>
          </div>
          <div class="col-md-4">
            <div class="socials">
              <h2>Redes Sociais</h2>
              <a href="https://www.facebook.com/NEECIST/" target="_blank">
                <i class="fa-brands fa-facebook icon" :style="{ color: 'white' }"></i>
              </a>
              <a href="https://twitter.com/NEECIST" target="_blank">
                <i class="fa-brands fa-twitter icon" :style="{ color: 'white' }"></i>
              </a>
              <a href="https://www.linkedin.com/company/2977028/" target="_blank">
                <i class="fa-brands fa-linkedin icon" :style="{ color: 'white' }"></i>
              </a>
              <a href="https://www.instagram.com/neecist/" target="_blank">
                <i class="fa-brands fa-instagram icon" :style="{ color: 'white' }"></i>
              </a>
              <a href="https://www.youtube.com/user/NEECIST" target="_blank">
                <i class="fa-brands fa-youtube icon" :style="{ color: 'white' }"></i>
              </a>
              <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
                <i class="fa-brands fa-spotify icon" :style="{ color: 'white' }"></i>
              </a>
            </div>
          </div>
          <div class="col-md-4">
            <div class="contact-adress">
              <p><i class="fa-solid fa-phone" :style="{ color: 'white', marginRight: '6px' }"></i> <a class="contact-address-text" href="tel:(+351) 218 419 056">(+351) 218 417 745</a></p>
              <p><i class="fa-solid fa-envelope" :style="{ color: 'white', marginRight: '6px' }"></i> <a class="contact-address-text" href="mailto:contacto@neecist.org">contacto@neecist.org</a></p>
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
    return {};
  },
};
</script>

<style>
.socials {
  text-align: center;
  font-size: 30px;
}
.socials h2 {
  font-size: 20px;
  margin-bottom: 10px;
  font-weight: bold;
  text-transform: uppercase;
  color: #ffffff;
}
.icon {
  color: white;
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
  position: absolute;
  width: 100%;
  bottom: 0;
  background-color: #303633;
  text-align: left;
}
.bottom-bar {
  margin-top: 10px;
  width: 100%;
  height: 30px;
  background-color: #303633;
  color: white;
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
  color: white;
  padding: 10px;
  padding-left: 10px;
}
.contact-adress {
  float: right;
  font-size: 16px;
  font-family: "Roboto";
  color: white;
  padding: 20px;
}
.contact-address-text {
  color: white;
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
