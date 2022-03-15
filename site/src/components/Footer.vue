<template>
    <div class="contacts-comp">
       <!--<component-title title="Contact Us" subtitle=""/>-->

       <section id="contact" class="section-bg wow fadeInUp">
            <div class="container">
                <div class="row contact-info">
                <div class="col-md-4">
                    <div class="contact-address">
                    <h3>Address</h3>
                    <address>Instituto Superior Técnico - Av. Rovisco Pais, 1049-001 Lisbon</address>
                    </div>
                </div>

                <div class="col-md-4">
                    <div class="contact-email">
                    <i class="ion-ios-email-outline"></i>
                    <h3>Email</h3>
                    <p><a href="mailto:contacto@neecist.org">contacto@neecist.org</a></p>
                    </div>
                </div>

                <div class="col-md-4">
                    <div class="contact-phone">
                    <h3>Phone</h3>
                    <p><a href="tel:(+351) 218 419 056">(+351) 218 419 056</a></p>
                    </div>
                </div>

                <div class="col-md-4">
                  <div class="socials">
                    <h3>Check our socials</h3>
                    <a href="https://www.facebook.com/NEECIST/" target="_blank">
                      <img  align="center" alt="facebook" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/facebook/facebook-plain.svg">
                    </a>
                    <a href="https://twitter.com/NEECIST" target="_blank">
                      <img  align="center" alt="twitter" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/twitter/twitter-original.svg">
                    </a>
                    <a href="https://www.linkedin.com/company/neecist/mycompany/" target="_blank">
                      <img  align="center" alt="linkedin" src="../../static/linkedin.svg">
                    </a>
                    <a href="https://www.instagram.com/neecist/" target="_blank">
                      <img  align="center" alt="instagram" src="../../static/instagram.svg">
                    </a>
                    <a href="https://www.youtube.com/user/NEECIST" target="_blank">
                      <img  align="center" alt="youtube" src="../../static/youtube2.svg">
                    </a>
                    <a href="https://open.spotify.com/show/1cIa5h27pb8ghnfDB7N8Mu" target="_blank">
                      <img  align="center" alt="spotify" src="../../static/spotify.svg">
                    </a>
                  </div>
                </div>

                </div>
            </div>
        </section>

        <div class="container">
          <div class="flexbox-imgs">
            <a href="https://tecnico.ulisboa.pt/pt/" target="_blank"><img src="../../static/partner-logos/ist_logo.png"></a>

            <a href="https://fenix.tecnico.ulisboa.pt/departamentos/deec" target="_blank"><img src="../../static/partner-logos/deec_logo.png"></a>
          </div>
        </div>


        <div class="bottom-bar">
            <div id="copyright">
                Copyright © 2022 - Núcleo de Estudantes de Eletrotécnica e de Computadores do Instituto Superior Técnico
            </div>
            <div id="source-code">
                Code hosted on 
                <a href="https://github.com/NEECIST/NeecUpdatedWebsite" target="_blank">
                  <img  align="center" alt="github" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/github/github-original.svg">
                </a>
            </div>
        </div>

    </div>
</template>


<script>
export default {
  name: 'footer-component',
  data() {
      return {
      }
  }
}   
</script>

<style>
.socials{
  text-align: center;
}
.socials h3 {
  font-size: 18px;
  margin-bottom: 10px;
  font-weight: bold;
  text-transform: uppercase;
  color: #112363;
}
.socials img {
  height: 30px;
  width: 40px;
  opacity: .85;
  transition: all .3s;
}
.socials img:hover {
	opacity: 1;
  -webkit-filter: grayscale(0%);
  filter: grayscale(0%);
}
#source-code img {
  height: 20px;
  width: 30px;
  opacity: .85;
  transition: all .3s;
}
#source-code img:hover {
	opacity: 1;
  -webkit-filter: grayscale(0%);
  filter: grayscale(0%);
}
.contacts-comp {
  position: relative;
  padding-top: 10px;
  background-color: #ffffff;
  text-align: left;
}
.bottom-bar {
  margin-top: 10px;
  width: 100%;
  height: 30px;
  background-color: rgb(255, 255, 255);
  color: rgb(0, 0, 0);
  position: relative;
  overflow: hidden;
  text-align: left;
  bottom: 0;
}
#copyright {
  padding-left: 10px;
  padding-bottom: 5px;
  padding-top: 9px;
  font-size: 13px;
  float: left;
  font-family: 'Lato', sans-serif;
}
#source-code {
  float: right;
  font-family: 'Lato', sans-serif;
  padding-right: 10px;
  padding-bottom: 5px;
  padding-top: 9px;
  font-size: 13px;
}
address {
    font-style: normal;
}
.flexbox-imgs {
  display: -webkit-box;  /* iOS 6-, Safari 3.1-6, BB7 */
  display: -ms-flexbox;  /* IE 10 */
  display: -webkit-flex; /* Safari 6.1+. iOS 7.1+, BB10 */
  display: flex;         /*Firefox, Chrome, Opera */
  
  flex-wrap: wrap;
  justify-content: center;
  align-items: center;
  flex-direction: row;
  margin-top: 20px;
}
.flexbox-imgs img {
  justify-content: center;
  max-height: 100px;
  max-width: 150px;
  margin: 5px 12px;
  padding-left: 30px;
  opacity: .85;
  transition: all .3s;
 
}
.flexbox-imgs img:hover {
	opacity: 1;
  -webkit-filter: grayscale(0%);
  filter: grayscale(0%);
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
#contact .contact-info {
  margin-bottom: 10px;
  text-align: center;
}
#contact .contact-info i {
  font-size: 48px;
  display: inline-block;
  margin-bottom: 10px;
  color: #f82249;
}
.col-md-4 {
  width: 25%;
  display: inline-block;
}
#contact .contact-info address,
#contact .contact-info p {
  margin-bottom: 0;
  color: #112363;
}
#contact .contact-info h3 {
  font-size: 20px;
  margin-bottom: 15px;
  font-weight: bold;
  text-transform: uppercase;
  color: #112363;
}
#contact .contact-info a {
  color: #4869df;
}
#contact .contact-info a:hover {
  color: #f82249;
}
#contact .contact-address,
#contact .contact-phone,
#contact .contact-email {
  font-size: 18px;
  margin-bottom: 10px;
  margin-left: 30px;
}
@media screen and (max-width: 560px) {
  .col-md-4 {
    width: 80%;
  }
}
</style>