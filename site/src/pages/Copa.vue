<template>
  <div class="copa-app" :style="{ padding: '10px', paddingTop: '77px', paddingBottom: '200px', fontFamily: 'Roboto' }">
    <h1>Apostas Mundial 2022</h1>
    <div :style="{ display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
      <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '2vh 0', backgroundColor: '#ddd', borderRadius: '10px' }">
        <h3>Login</h3>
        <div :style="{ display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
          <div :style="{ width: '100%', padding: '1vh 2vw', margin: '1vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
            <input
              type="text"
              placeholder="Username/Nome de Display"
              v-model="username"
              :style="{ width: '100%', padding: '1vh 0vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }"
            />
          </div>
          <div :style="{ width: '100%', padding: '1vh 2vw', margin: '1vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
            <input
              type="text"
              placeholder="Password (isto não vai estar encriptado)"
              v-model="password"
              :style="{minWidth: '350px', width: '100%', padding: '1vh 0vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }"
            />
          </div>
          <div :style="{ width: '100%', padding: '1vh 2vw', margin: '1vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
            <button @click="login" :style="{ width: '100%', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: 'rgb(30 156 216)', borderRadius: '10px' }">Login/Criar Conta</button>
            </div>
        </div>
      </div>
      <div v-if="initialized1 && initialized2" :style="{overflow: 'auto', width:'100%'}">
        <div class="table100" >
          <table>
            <thead>
              <tr class="table100-head">
                <th>Data</th>
                <th>Equipas</th>
                <th>Resultado</th>
                <th v-for="person in passwords" :key="person.name">{{ person.name }}</th>
              </tr>
            </thead>
            <tbody>
              <tr v-for="(match, id) in matches" :key="match.id">
                <td>{{ match.date }}</td>
                <td>{{ match.team1 }} vs {{ match.team2 }}</td>
                <td :match="id" @input="resultChange" :contenteditable="this.password == 'omelhor' ? true : false">{{ match.final }}</td>
                <td v-for="person in passwords" :key="person.name" :class=[person.name] :match="id" @input="cellChange" :contenteditable="this.password == person.password && this.username == person.name  ? true : false">{{ match.bets[person.name] }}</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div :style="{ display: 'flex', justifyContent: 'center' }" v-else>
        <PulseLoader :color="'#009DE0'"></PulseLoader>
      </div>
    </div>
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
      
      fetch("https://copa22.midas-cloud.xyz/passwords", {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({ name: this.username, password: this.password })
      });
    },
    cellChange(e) {
      var updated;
      var match = e.target.getAttribute("match");
      var name = e.target.className;
      this.matches[match].bets[name] = e.target.innerText;

      fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`)
      .then((response) => response.json())
      .then((json) => {
        updated = json;
      }).then(() => {
        updated.bets[name] = e.target.innerText;
        fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`, {
          method: "PUT",
          headers: {
            "Content-Type": "application/json",
          },
          body: JSON.stringify(updated),
        });
        this.matches[match].bets = updated.bets;
      });
    },
    resultChange(e){
      var updated;
      var match = e.target.getAttribute("match");
      fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`)
      .then((response) => response.json())
      .then((json) => {
        updated = json;
      }).then(() => {
        updated.final = e.target.innerText;
        fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`, {
          method: "PUT",
          headers: {
            "Content-Type": "application/json",
          },
          body: JSON.stringify(updated),
        });
        this.matches[match].final = e.target.innerText;
      });
    }
  },
  created() {
    fetch("https://copa22.midas-cloud.xyz/jogos")
      .then((response) => response.json())
      .then((json) => {
        json.forEach((match) => {
          this.matches[match.id] = match;
        });
      })
      .finally(() => {
        this.initialized1 = true;
      });
    fetch("https://copa22.midas-cloud.xyz/passwords")
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
