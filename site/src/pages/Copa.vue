
<template>
    <div class="error-comp">
        <div>
            <img src="https://clipart.info/images/ccovers/1496175203emoji-android-heavy-exclamation-mark-symbol.png">
        </div>
        <div class="error-msg">A redirecionar para a drive<p>Por favor aguarda</p></div>
    </div>
</template>
<script>
import PulseLoader from "vue-spinner/src/PulseLoader.vue";
export default {
  name: "copa-page",
  data() {
    return {
      initialized1: false,
      initialized2: false,
      matches: {},
      bets: [],
      passwords: [],
      username: "",
      password: ""
    };
  },
  methods: {
    login() {
      if (this.username == "" || this.password == "" || this.username == undefined || this.password == undefined) {
        alert("Preenche os campos");
        return;
      }
      var existsName = false;
      //Check if user exists
      this.passwords.forEach((person) => {
        console.log(person.name, this.username);
        if (person.name == this.username) {
          
          existsName = true;
          console.log(person.password, this.password);
          if (person.password != this.password) {
            alert("Um utilizador com esse nome já existe, mas a password está errada");
            return;
          }
        }
      });
      if(existsName)
        return;

      alert('Conta criada, para editar os resultados clica no resultado a alterar');
      Object.entries(this.matches).forEach((match) => {
        this.matches[match[0]].bets[this.username] = "0-0";
      });
      this.passwords.push({ name: this.username, password: this.password });  
      
      fetch("http://copa22.midas-cloud.xyz/passwords", {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({ name: this.username, password: this.password })
      });
    },
    cellChange(e) {
      var updated;
      console.log(e.target.innerText);
      var match = e.target.getAttribute("match");
      var name = e.target.className;
      this.matches[match].bets[name] = e.target.innerText;

      fetch(`http://copa22.midas-cloud.xyz/jogos/${match}`)
      .then((response) => response.json())
      .then((json) => {
        updated = json;
      }).then(() => {
        updated.bets[name] = e.target.innerText;
        fetch(`http://copa22.midas-cloud.xyz/jogos/${match}`, {
          method: "PUT",
          headers: {
            "Content-Type": "application/json",
          },
          body: JSON.stringify(updated),
        });
        this.matches[match].bets = updated.bets;
      });
    },
    saveChanges() {
            
    }
  },
  created() {
    fetch("http://copa22.midas-cloud.xyz/jogos")
      .then((response) => response.json())
      .then((json) => {
        json.forEach((match) => {
          this.matches[match.id] = match;
        });
      })
      .finally(() => {
        this.initialized1 = true;
      });
    fetch("http://copa22.midas-cloud.xyz/passwords")
      .then((response) => response.json())
      .then((json) => {
        this.passwords = json;
      })
      .finally(() => {
        this.initialized2 = true;
      });
  },

  components: { PulseLoader },
};
</script>

<style scoped>
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}
body,
html {
  height: 100%;
  font-family: sans-serif;
}
a {
  margin: 0;
  transition: all 0.4s;
  -webkit-transition: all 0.4s;
  -o-transition: all 0.4s;
  -moz-transition: all 0.4s;
}
a:focus {
  outline: none !important;
}
a:hover {
  text-decoration: none;
}
h1,
h2,
h3,
h4,
h5,
h6 {
  margin: 0;
}
p {
  margin: 0;
}
ul,
li {
  margin: 0;
  list-style-type: none;
}
input {
  display: block;
  outline: none;
  border: none !important;
}
textarea {
  display: block;
  outline: none;
}
textarea:focus,
input:focus {
  border-color: transparent !important;
}
button {
  outline: none !important;
  border: none;
  background: 0 0;
}
button:hover {
  cursor: pointer;
}
iframe {
  border: none !important;
}
.limiter {
  width: 100%;
  margin: 0 auto;
}
.container-table100 {
  width: 100%;
  min-height: 100vh;
  background: #c850c0;
  background: -webkit-linear-gradient(45deg, #4158d0, #c850c0);
  background: -o-linear-gradient(45deg, #4158d0, #c850c0);
  background: -moz-linear-gradient(45deg, #4158d0, #c850c0);
  background: linear-gradient(45deg, #4158d0, #c850c0);
  display: -webkit-box;
  display: -webkit-flex;
  display: -moz-box;
  display: -ms-flexbox;
  display: flex;
  align-items: center;
  justify-content: center;
  flex-wrap: wrap;
  padding: 33px 30px;
}
.wrap-table100 {
  width: 1170px;
}
table {
  border-spacing: 1;
  border-collapse: collapse;
  background: #fff;
  border-radius: 10px;
  overflow: hidden;
  margin: 0 auto;
  position: relative;
}
table * {
  position: relative;
}

table {
  padding-left: 8px;
}
table thead tr {
  height: 60px;
  background: #36304a;
}
table tbody tr {
  height: 50px;
}
table tbody tr:last-child {
  border: 0;
}
table td,
table th {
  text-align: left;
}
table td.l,
table th.l {
  text-align: right;
}
table td.c,
table th.c {
  text-align: center;
}
table td.r,
table th.r {
  text-align: center;
}
.table100-head th {
  font-size: 18px;
  color: #fff;
  line-height: 1.2;
  font-weight: unset;
}
tbody tr:nth-child(even) {
  background-color: #f5f5f5;
}
tbody tr {
  font-size: 15px;
  color: gray;
  line-height: 1.2;
  font-weight: unset;
}
tbody tr:hover {
  color: #555;
  background-color: #f5f5f5;
  cursor: pointer;
}
th,
td {
  padding-inline: 40px;
}
</style>
