<template>
  <div class="copa-app" :style="{ padding: '10px', paddingTop: '77px', paddingBottom: '200px', fontFamily: 'Roboto' }">
    <h1>Apostas Mundial 2022</h1>
    <div :style="{ display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
      
      <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '2vh 0', backgroundColor: '#ddd', borderRadius: '10px' }">
        <h2>Login</h2>
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
              :style="{ minWidth: '350px', width: '100%', padding: '1vh 0vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }"
            />
          </div>
          <div :style="{ width: '100%', padding: '1vh 2vw', margin: '1vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
            <button @click="login" :style="{ width: '100%', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: 'rgb(30 156 216)', borderRadius: '10px' }">Login/Criar Conta</button>
          </div>
        </div>
      </div>
      <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '0 0 2vh 0 ', backgroundColor: '#ddd', borderRadius: '10px' }">
        <h2>Regras Pontuações:</h2>
        <ul>
          <li>Acertar o resultado final: +1 pontos</li>
          <li>Acertar o número de golos de cada equipa: +2 pontos</li>
        </ul>
      </div>
      <div v-if="initialized1 && initialized2 && initialized3" :style="{ overflow: 'auto', width: '100%' }">
        <div class="table100">
          <table>
            <thead>
              <tr class="table100-head">
                <th>Data</th>
                <th>Equipas</th>
                <th>Resultado</th>
                <th v-for="person in passwords" :key="person.name">{{ person.name }}</th>
                <th v-if="this.username == 'Midas' && this.password == 'omelhor'">Fechar Jogo</th>
                <th v-if="this.username == 'Midas' && this.password == 'omelhor'">Calcular Scores</th>
              </tr>
            </thead>
            <tbody>
              <tr v-for="(match, id) in matches" :key="match.id">
                <td>{{ match.date }}</td>
                <td>{{ match.team1 }} vs {{ match.team2 }}</td>
                <td :match="id" @input="resultChange" :contenteditable="this.password == 'omelhor' ? true : false">{{ match.final }}</td>
                <td
                 :style="  {cursor: match.closed ?'not-allowed' : 'pointer', backgroundColor: scores[person.id].individual[id] == 3 ? '#a8ffa8' : scores[person.id].individual[id] == 1 ? '#ffffa7' : 'unset' } "
                  v-for="person in passwords"
                  :key="person.name"
                  :class="[person.name]"
                  :match="id"
                  @input="cellChange"
                  :contenteditable="this.password == person.password && this.username == person.name ? true : false"
                  :title="match.closed ? 'As apostas para este jogo já fecharam!' : null"
                >
                  {{ match.bets[person.name] }}
                </td>
                <td v-if="this.username == 'Midas' && this.password == 'omelhor'">
                  <input type="checkbox" :match="id" @change="closeMatch" :checked="match.closed" :disabled="this.password == 'omelhor' ? false : true" />
                </td>
                <td v-if="this.username == 'Midas' && this.password == 'omelhor'">
                  <button :match="id" @click="calculateScores" :disabled="this.password == 'omelhor' ? false : true">Calcular Scores</button>
                </td>
              </tr>
            </tbody>
            <tfoot>
              <tr class="table100-head">
                <th colspan="3">Scores</th>
                <th v-for="person in scores" :key="person.name">{{ person.score }}</th>
              </tr>
            </tfoot>
          </table>
          <button
            v-if="this.username == 'Midas' && this.password == 'omelhor'"
            @click="updateIDs"
            :style="{ width: '100%', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: 'rgb(30 156 216)', borderRadius: '10px' }"
          >
            Update IDs
          </button>
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
      initialized3: false,
      scores: {},
      matches: {},
      bets: [],
      passwords: [],
      username: "",
      password: "",
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
      if (existsName) return;

      alert("Conta criada, para editar os resultados clica no resultado a alterar");
      Object.entries(this.matches).forEach((match) => {
        this.matches[match[0]].bets[this.username] = "0-0";
      });
      this.passwords.push({ name: this.username, password: this.password });


      fetch("https://copa22.midas-cloud.xyz/passwords", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ name: this.username, password: window.btoa(this.password) }),
      });
      fetch("https://copa22.midas-cloud.xyz/scores", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ name: this.username, score: 0, individual:[]}),
      });
    },
    cellChange(e) {
      var updated;
      var match = e.target.getAttribute("match");
      var name = e.target.className;
      var pass;
      this.passwords.forEach((person) => {
        if (person.name == name) {
          pass = person.password;
        }
      });
      if (this.password !== pass) {
        alert("Malandro a tentar alterar as apostas dos outros");
        return;
      }
      if (this.matches[match].closed) {
        alert("As apostas para este jogo já estão fechadas");
        return;
      }

      this.matches[match].bets[name] = e.target.innerText;

      fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`)
        .then((response) => response.json())
        .then((json) => {
          updated = json;
        })
        .then(() => {
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
    resultChange(e) {
      var updated;
      var match = e.target.getAttribute("match");
      fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`)
        .then((response) => response.json())
        .then((json) => {
          updated = json;
        })
        .then(() => {
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
    },
    closeMatch(e) {
      let updated;
      let match = e.target.getAttribute("match");
      fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`)
        .then((response) => response.json())
        .then((json) => {
          updated = json;
        })
        .then(() => {
          updated.closed = e.target.checked;
          updated.finished = e.target.checked;
          fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`, {
            method: "PUT",
            headers: {
              "Content-Type": "application/json",
            },
            body: JSON.stringify(updated),
          });
          this.matches[match].closed = e.target.checked;
        });
    },
    calculateScores() {
      console.log("Calculating scores");
      console.log(this.scores);
     Object.keys(this.scores).forEach((person) => {
      console.log(person, this.scores[person].name);
        let updated_scores = Array.apply(null, Array(this.matches.length)).map(function () {
          return 0;
        });
        Object.keys(this.matches).forEach((match) => {
          if (this.matches[match].finished) {
            console.log("Match finished", match);
            updated_scores[match] = this.calculatePoints(this.scores[person].name, match);
          }
        });
        this.scores[person].individual = updated_scores;
        this.scores[person].score = updated_scores.reduce((a, b) => a + b, 0);
      });

      Object.keys(this.scores).forEach((person) => {
        setTimeout(() => {
          fetch(`https://copa22.midas-cloud.xyz/scores/${person}`, {
            method: "PUT",
            headers: {
              "Content-Type": "application/json",
            },
            body: JSON.stringify(this.scores[person]),
          });
        }, 1000 * person);
      });
    },
    calculatePoints(name, match) {
      if( this.matches[match].bets[name] == undefined) return 0;
      let score = 0;
      let matchScore = this.matches[match].final.split("-");
      let betScore = this.matches[match].bets[name].split("-");
      if (matchScore[0] == betScore[0] && matchScore[1] == betScore[1]) {
        score += 2;
      }
      if (matchScore[0] > matchScore[1] && betScore[0] > betScore[1]) {
        score += 1;
      }
      if (matchScore[0] < matchScore[1] && betScore[0] < betScore[1]) {
        score += 1;
      }
      if (matchScore[0] == matchScore[1] && betScore[0] == betScore[1]) {
        score += 1;
      }
      return score;
    },
    updateIDs() {
      let updated;
      let apiIds = [
        391882, 391887, 391881, 391888, 391893, 391899, 391894, 391900, 391911, 391905, 391906, 391912, 391917, 391923, 391924, 391918, 391889, 391883, 391884, 391890, 391901, 391895, 391902, 391896,
        391907, 391913, 391914, 391908, 391919, 391925, 391920, 391926, 391885, 391886, 391891, 391892, 391903, 391904, 391897, 391898, 391915, 391916, 391909, 391910, 391927, 391928, 391921, 391922,
        391929, 391930, 391931, 391932, 391933, 391934, 391935, 391936, 391937, 391938, 391939, 391940, 391941, 391942, 391943, 391944,
      ];
      Object.keys(this.matches).forEach((match) => {
        setTimeout(() => {
          fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`)
            .then((response) => response.json())
            .then((json) => {
              updated = json;
            })
            .then(() => {
              updated.apiID = apiIds[match];
              fetch(`https://copa22.midas-cloud.xyz/jogos/${match}`, {
                method: "PUT",
                headers: {
                  "Content-Type": "application/json",
                },
                body: JSON.stringify(updated),
              });
            });
        }, 1000 * this.matches[match].id);
      });
    },
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
        var decoded;
        for (var i = 0; i < this.passwords.length; i++) {
          decoded = window.atob(this.passwords[i].password);
          this.passwords[i].password = decoded;
        }
      })
      .finally(() => {
        this.initialized2 = true;
      });

    fetch("https://copa22.midas-cloud.xyz/scores")
      .then((response) => response.json())
      .then((json) => {
        json.forEach((person) => {
          this.scores[person.id] = person;
        });
      })
      .finally(() => {
        this.initialized3 = true;
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
table thead tr,
table tfoot tr {
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
  text-align: center;
  font-weight: bold;
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
.table100-head th,
tfoot th {
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
