<template>
  <div class="copa-app" :style="{ padding: '10px', paddingTop: '77px', paddingBottom: '200px', fontFamily: 'Roboto' }">
    <h1>Apostas Mundial 2022</h1>

    <div :style="{ display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
      <div :style="{ display: 'flex' }">
        <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '2vh 2vw', backgroundColor: '#ddd', borderRadius: '10px' }">
          <h2>Leaderboard Fase de Grupos:</h2>
          <div :style="{ display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
            <div v-if="initialized3" :style="{ width: '100%', padding: '1vh 2vw', margin: '1vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
              <div v-for="person in leaderboardFaseGrupos" :key="person.name" :style="{ display: 'flex', flexDirection: 'row', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
                <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
                  {{ person.name }}
                </div>
                <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
                  {{ person.score }}
                </div>
              </div>
            </div>
          </div>
        </div>
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
        <div v-if="initialized1 && initialized2 && initialized3" :style="{ width: 'auto', padding: '1vh 2vw', margin: '2vh 2vw', backgroundColor: '#ddd', borderRadius: '10px' }">
          <h2>Leaderboard Fase de Eleminação:</h2>
          <div :style="{ display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
            <div v-if="initialized3" :style="{ width: '100%', padding: '1vh 2vw', margin: '1vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
              <div v-for="person in sortedScore" :key="person.name" :style="{ display: 'flex', flexDirection: 'row', justifyContent: 'space-between', alignItems: 'center', width: '100%' }">
                <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
                  {{ person.name }}
                </div>
                <div :style="{ width: 'auto', padding: '1vh 2vw', margin: '0vh 0', backgroundColor: '#fff', borderRadius: '10px' }">
                  {{ person.score }}
                </div>
              </div>
            </div>
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
        <h2 :style="{ marginTop: '3vh' }">Quartos de Final</h2>
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
                  :style="{
                    cursor: match.closed ? 'not-allowed' : 'pointer',
                    backgroundColor: scores[person.id].individual[id] == 3 ? '#a8ffa8' : scores[person.id].individual[id] == 1 ? '#ffffa7' : 'unset',
                  }"
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
        <h2 :style="{ marginTop: '3vh' }">Oitavos de Final</h2>
        <div class="table100" data-v-570d5bb6="">
          <table data-v-570d5bb6="">
            <thead data-v-570d5bb6="">
              <tr class="table100-head" data-v-570d5bb6="">
                <th data-v-570d5bb6="">Data</th>
                <th data-v-570d5bb6="">Equipas</th>
                <th data-v-570d5bb6="">Resultado</th>
                <th data-v-570d5bb6="">Midas</th>
                <th data-v-570d5bb6="">14Animes</th>
                <th data-v-570d5bb6="">Gabriel</th>
                <th data-v-570d5bb6="">dishadow</th>
                <th data-v-570d5bb6="">cerdas</th>
                <th data-v-570d5bb6="">MO</th>
                <th data-v-570d5bb6="">Madalena</th>
                <th data-v-570d5bb6="">Paulo Portas</th>
              </tr>
            </thead>
            <tbody data-v-570d5bb6="">
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Sábado, 2/dez 15:00</td>
                <td data-v-570d5bb6="">Holanda vs Estados Unidos</td>
                <td match="0" contenteditable="false" data-v-570d5bb6="">3-1</td>
                <td class="Midas" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-1
                </td>
                <td
                  class="14Animes"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="Gabriel"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="cerdas" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">(V) 1-1</td>
                <td class="MO" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Madalena" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">(V) 1-1</td>
                <td class="Paulo Portas" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Sábado, 2/dez 19:00</td>
                <td data-v-570d5bb6="">Argentina vs Austrália</td>
                <td match="1" contenteditable="false" data-v-570d5bb6="">2-1</td>
                <td class="Midas" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="14Animes"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="cerdas"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="MO" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td class="Madalena" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">(V) 1-1</td>
                <td
                  class="Paulo Portas"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Domingo, 3/dez 15:00</td>
                <td data-v-570d5bb6="">França vs Polónia</td>
                <td match="2" contenteditable="false" data-v-570d5bb6="">3-1</td>
                <td class="Midas" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="14Animes"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="cerdas"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="MO" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  3-0
                </td>
                <td class="Madalena" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Paulo Portas"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Domingo, 3/dez 19:00</td>
                <td data-v-570d5bb6="">Inglaterra vs Senegal</td>
                <td match="3" contenteditable="false" data-v-570d5bb6="">3-0</td>
                <td class="Midas" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="14Animes"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Gabriel"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="dishadow"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  4-0
                </td>
                <td
                  class="cerdas"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  3-0
                </td>
                <td class="MO" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">2-3</td>
                <td class="Madalena" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Paulo Portas"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Segunda, 5/dez 15:00</td>
                <td data-v-570d5bb6="">Japão vs Croácia</td>
                <td match="4" contenteditable="false" data-v-570d5bb6="">1-1 (V)</td>
                <td class="Midas" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(168, 255, 168)">
                  1-1 (V)
                </td>
                <td class="14Animes" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Gabriel" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="dishadow"
                  match="4"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  (V) 1-1
                </td>
                <td class="cerdas" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="MO" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Madalena" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Paulo Portas"
                  match="4"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Segunda, 5/dez 19:00</td>
                <td data-v-570d5bb6="">Brasil vs Coreia do Sul</td>
                <td match="5" contenteditable="false" data-v-570d5bb6="">4-1</td>
                <td class="Midas" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  3-0
                </td>
                <td
                  class="14Animes"
                  match="5"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="Gabriel"
                  match="5"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="dishadow"
                  match="5"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="cerdas"
                  match="5"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td class="MO" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-1
                </td>
                <td class="Madalena" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Paulo Portas"
                  match="5"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Terça, 6/dez 15:00</td>
                <td data-v-570d5bb6="">Marrocos vs Espanha</td>
                <td match="6" contenteditable="false" data-v-570d5bb6="">(V) 0-0</td>
                <td class="Midas" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">0-2</td>
                <td class="14Animes" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">1-3</td>
                <td
                  class="Gabriel"
                  match="6"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: unset; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="dishadow" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">1-3</td>
                <td
                  class="cerdas"
                  match="6"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="MO" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">0-2</td>
                <td class="Madalena" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">1-2</td>
                <td class="Paulo Portas" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed">0-2</td>
              </tr>
              <tr data-v-570d5bb6="">
                <td data-v-570d5bb6="">Terça, 6/dez 19:00</td>
                <td data-v-570d5bb6="">Portugal vs Suiça</td>
                <td match="7" contenteditable="false" data-v-570d5bb6="">6-1</td>
                <td class="Midas" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-1
                </td>
                <td
                  class="14Animes"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="dishadow"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="cerdas"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="MO" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-570d5bb6="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  1-0
                </td>
                <td
                  class="Madalena"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-2
                </td>
                <td
                  class="Paulo Portas"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-570d5bb6=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <!----><!---->
              </tr>
            </tbody>
            <tfoot data-v-570d5bb6="">
              <tr class="table100-head" data-v-570d5bb6="">
                <th colspan="3" data-v-570d5bb6="">Scores</th>
                <th data-v-570d5bb6="">10</th>
                <th data-v-570d5bb6="">6</th>
                <th data-v-570d5bb6="">7</th>
                <th data-v-570d5bb6="">9</th>
                <th data-v-570d5bb6="">8</th>
                <th data-v-570d5bb6="">4</th>
                <th data-v-570d5bb6="">1</th>
                <th data-v-570d5bb6="">8</th>
              </tr>
            </tfoot>
          </table>
          <!---->
        </div>
        <h2 :style="{ marginTop: '3vh' }">Fase de Grupos</h2>
        <div class="table100" data-v-58113781="">
          <table data-v-58113781="">
            <thead data-v-58113781="">
              <tr class="table100-head" data-v-58113781="">
                <th data-v-58113781="">Data</th>
                <th data-v-58113781="">Equipas</th>
                <th data-v-58113781="">Resultado</th>
                <th data-v-58113781="">Midas</th>
                <th data-v-58113781="">14Animes</th>
                <th data-v-58113781="">Gabriel</th>
                <th data-v-58113781="">moniquita</th>
                <th data-v-58113781="">dishadow</th>
                <th data-v-58113781="">cerdas</th>
                <th data-v-58113781="">MO</th>
                <th data-v-58113781="">Madalena</th>
                <th data-v-58113781="">Paulo Portas</th>
                <th data-v-58113781="">André Pereira</th>
                <th data-v-58113781="">Not mimi</th>
                <th data-v-58113781="">Antunes</th>
                <!--v-if--><!--v-if-->
              </tr>
            </thead>
            <tbody data-v-58113781="">
              <tr data-v-58113781="">
                <td data-v-58113781="">Domingo, 20/nov 16:00</td>
                <td data-v-58113781="">Catar vs Equador</td>
                <td match="0" contenteditable="false" data-v-58113781="">0-2</td>
                <td class="Midas" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  0-1
                </td>
                <td
                  class="14Animes"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-2
                </td>
                <td
                  class="Gabriel"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td
                  class="moniquita"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="dishadow"
                  match="0"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-2
                </td>
                <td class="cerdas" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="MO" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Madalena" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Paulo Portas" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="0" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 21/nov 13:00</td>
                <td data-v-58113781="">Inglaterra vs Irão</td>
                <td match="1" contenteditable="false" data-v-58113781="">6-2</td>
                <td class="Midas" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="14Animes"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="Gabriel"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="moniquita"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="cerdas"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td class="MO" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-1
                </td>
                <td class="Madalena" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Paulo Portas"
                  match="1"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="André Pereira" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="1" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 21/nov 16:00</td>
                <td data-v-58113781="">Senegal vs Países Baixos</td>
                <td match="2" contenteditable="false" data-v-58113781="">0-2</td>
                <td class="Midas" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(168, 255, 168)">
                  0-2
                </td>
                <td
                  class="14Animes"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Gabriel"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="moniquita"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="dishadow"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="cerdas"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="MO" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(168, 255, 168)">
                  0-2
                </td>
                <td
                  class="Madalena"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Paulo Portas"
                  match="2"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-2
                </td>
                <td class="André Pereira" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="2" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 21/nov 21:00</td>
                <td data-v-58113781="">Estados Unidos vs País de Gales</td>
                <td match="3" contenteditable="false" data-v-58113781="">1-1</td>
                <td class="Midas" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(168, 255, 168)">
                  1-1
                </td>
                <td class="14Animes" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="Gabriel" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td
                  class="moniquita"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-1
                </td>
                <td
                  class="dishadow"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-1
                </td>
                <td class="cerdas" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="MO" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td
                  class="Madalena"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-1
                </td>
                <td
                  class="Paulo Portas"
                  match="3"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-1
                </td>
                <td class="André Pereira" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="3" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 22/nov 10:00</td>
                <td data-v-58113781="">Argentina vs Arábia Saudita</td>
                <td match="4" contenteditable="false" data-v-58113781="">1-2</td>
                <td class="Midas" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">5-1</td>
                <td class="14Animes" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="Gabriel" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="moniquita" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="dishadow" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="cerdas" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">4-0</td>
                <td class="MO" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">4-0</td>
                <td class="Madalena" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Paulo Portas" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="André Pereira" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="4" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 22/nov 13:00</td>
                <td data-v-58113781="">Dinamarca vs Tunísia</td>
                <td match="5" contenteditable="false" data-v-58113781="">0-0</td>
                <td class="Midas" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="14Animes" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Gabriel" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="moniquita" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="dishadow" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="cerdas" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="MO" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Madalena" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Paulo Portas" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="André Pereira" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="5" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 22/nov 16:00</td>
                <td data-v-58113781="">México vs Polônia</td>
                <td match="6" contenteditable="false" data-v-58113781="">0-0</td>
                <td class="Midas" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  1-1
                </td>
                <td class="14Animes" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-3</td>
                <td class="Gabriel" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="moniquita" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="dishadow" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td
                  class="cerdas"
                  match="6"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-0
                </td>
                <td class="MO" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td
                  class="Madalena"
                  match="6"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-2
                </td>
                <td
                  class="Paulo Portas"
                  match="6"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td class="André Pereira" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="6" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 22/nov 19:00</td>
                <td data-v-58113781="">França vs Austrália</td>
                <td match="7" contenteditable="false" data-v-58113781="">4-1</td>
                <td class="Midas" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  3-1
                </td>
                <td
                  class="14Animes"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="moniquita"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="dishadow"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="cerdas"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="MO" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  3-0
                </td>
                <td
                  class="Madalena"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Paulo Portas"
                  match="7"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="André Pereira" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Not mimi" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="7" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 23/nov 10:00</td>
                <td data-v-58113781="">Marrocos vs Croácia</td>
                <td match="8" contenteditable="false" data-v-58113781="">0-0</td>
                <td class="Midas" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="14Animes" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Gabriel" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="moniquita" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="dishadow" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="cerdas" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="MO" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Madalena" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td
                  class="Paulo Portas"
                  match="8"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="8"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-0
                </td>
                <td class="Not mimi" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="8" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 23/nov 13:00</td>
                <td data-v-58113781="">Alemanha vs Japão</td>
                <td match="9" contenteditable="false" data-v-58113781="">1-2</td>
                <td class="Midas" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="14Animes" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="Gabriel" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="moniquita" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="dishadow" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">5-2</td>
                <td class="cerdas" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="MO" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Madalena" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="Paulo Portas" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="André Pereira" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-0
                </td>
                <td class="Not mimi" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="9" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 23/nov 16:00</td>
                <td data-v-58113781="">Espanha vs Costa Rica</td>
                <td match="10" contenteditable="false" data-v-58113781="">7-0</td>
                <td
                  class="Midas"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  4-0
                </td>
                <td
                  class="14Animes"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="Gabriel" match="10" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td
                  class="moniquita"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="dishadow"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  4-1
                </td>
                <td
                  class="cerdas"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="MO" match="10" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="Madalena"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Paulo Portas"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="André Pereira"
                  match="10"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="Not mimi" match="10" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="10" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 23/nov 19:00</td>
                <td data-v-58113781="">Bélgica vs Canadá</td>
                <td match="11" contenteditable="false" data-v-58113781="">1-0</td>
                <td
                  class="Midas"
                  match="11"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="14Animes"
                  match="11"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  4-1
                </td>
                <td class="Gabriel" match="11" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="moniquita" match="11" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="dishadow"
                  match="11"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="cerdas"
                  match="11"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-0
                </td>
                <td class="MO" match="11" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="Madalena"
                  match="11"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Paulo Portas"
                  match="11"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="André Pereira" match="11" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-0
                </td>
                <td class="Not mimi" match="11" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Antunes" match="11" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 24/nov 10:00</td>
                <td data-v-58113781="">Suíça vs Camarões</td>
                <td match="12" contenteditable="false" data-v-58113781="">1-0</td>
                <td class="Midas" match="12" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="14Animes" match="12" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Gabriel" match="12" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td
                  class="moniquita"
                  match="12"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="dishadow"
                  match="12"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="cerdas"
                  match="12"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-0
                </td>
                <td class="MO" match="12" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td
                  class="Madalena"
                  match="12"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="Paulo Portas" match="12" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="12"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="Not mimi"
                  match="12"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="Antunes" match="12" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 24/nov 13:00</td>
                <td data-v-58113781="">Uruguai vs Coreia do Sul</td>
                <td match="13" contenteditable="false" data-v-58113781="">0-0</td>
                <td class="Midas" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="14Animes" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Gabriel" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="dishadow" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">4-1</td>
                <td class="cerdas" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="MO" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Madalena" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Paulo Portas" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="André Pereira" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-1
                </td>
                <td class="Not mimi" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Antunes" match="13" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">20</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 24/nov 16:00</td>
                <td data-v-58113781="">Portugal vs Gana</td>
                <td match="14" contenteditable="false" data-v-58113781="">3-2</td>
                <td
                  class="Midas"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="14Animes"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Gabriel"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="moniquita"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="dishadow"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="cerdas"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td class="MO" match="14" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-1
                </td>
                <td
                  class="Madalena"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="Paulo Portas"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="André Pereira"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Not mimi"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Antunes"
                  match="14"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 24/nov 19:00</td>
                <td data-v-58113781="">Brasil vs Sérvia</td>
                <td match="15" contenteditable="false" data-v-58113781="">2-0</td>
                <td
                  class="Midas"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="14Animes"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="Gabriel"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="moniquita"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="dishadow"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="cerdas"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td class="MO" match="15" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  3-0
                </td>
                <td
                  class="Madalena"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  4-0
                </td>
                <td
                  class="Paulo Portas"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="André Pereira"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="Not mimi"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Antunes"
                  match="15"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 25/nov 10:00</td>
                <td data-v-58113781="">País de Gales vs Irão</td>
                <td match="16" contenteditable="false" data-v-58113781="">0-2</td>
                <td class="Midas" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="14Animes" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Gabriel" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="moniquita" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="dishadow" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <td class="cerdas" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="MO" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  1-2
                </td>
                <td
                  class="Madalena"
                  match="16"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="Paulo Portas" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="16"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-2
                </td>
                <td class="Not mimi" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="Antunes" match="16" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 25/nov 13:00</td>
                <td data-v-58113781="">Catar vs Senegal</td>
                <td match="17" contenteditable="false" data-v-58113781="">1-3</td>
                <td class="Midas" match="17" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="14Animes"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="Gabriel"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td class="moniquita" match="17" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="dishadow"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="cerdas"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td class="MO" match="17" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  0-3
                </td>
                <td
                  class="Madalena"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-3
                </td>
                <td
                  class="Paulo Portas"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td class="André Pereira" match="17" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-0
                </td>
                <td
                  class="Not mimi"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="Antunes"
                  match="17"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 25/nov 16:00</td>
                <td data-v-58113781="">Países Baixos vs Equador</td>
                <td match="18" contenteditable="false" data-v-58113781="">1-1</td>
                <td class="Midas" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="14Animes" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Gabriel" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td
                  class="dishadow"
                  match="18"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-2
                </td>
                <td class="cerdas" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="MO" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(168, 255, 168)">
                  1-1
                </td>
                <td class="Madalena" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td
                  class="Paulo Portas"
                  match="18"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-1
                </td>
                <td class="André Pereira" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-0
                </td>
                <td class="Not mimi" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Antunes" match="18" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 25/nov 19:00</td>
                <td data-v-58113781="">Inglaterra vs Estados Unidos</td>
                <td match="19" contenteditable="false" data-v-58113781="">0-0</td>
                <td class="Midas" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="14Animes" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="Gabriel" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="dishadow" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="cerdas" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="MO" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="Madalena" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Paulo Portas" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="André Pereira" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="Not mimi" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-0</td>
                <td class="Antunes" match="19" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sábado, 26/nov 10:00</td>
                <td data-v-58113781="">Tunísia vs Austrália</td>
                <td match="20" contenteditable="false" data-v-58113781="">0-1</td>
                <td class="Midas" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="14Animes" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Gabriel" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="dishadow"
                  match="20"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-1
                </td>
                <td class="cerdas" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="MO" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="Madalena" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Paulo Portas" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="20"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td class="Not mimi" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="Antunes" match="20" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sábado, 26/nov 13:00</td>
                <td data-v-58113781="">Polônia vs Arábia Saudita</td>
                <td match="21" contenteditable="false" data-v-58113781="">2-0</td>
                <td
                  class="Midas"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="14Animes"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Gabriel"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="moniquita"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="cerdas" match="21" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="MO" match="21" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  1-0
                </td>
                <td
                  class="Madalena"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="Paulo Portas" match="21" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="Not mimi"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="Antunes"
                  match="21"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sábado, 26/nov 16:00</td>
                <td data-v-58113781="">França vs Dinamarca</td>
                <td match="22" contenteditable="false" data-v-58113781="">2-1</td>
                <td
                  class="Midas"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-1
                </td>
                <td class="14Animes" match="22" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="Gabriel"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-1
                </td>
                <td
                  class="moniquita"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="cerdas"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td class="MO" match="22" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="Madalena" match="22" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="Paulo Portas"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="André Pereira"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Not mimi"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-1
                </td>
                <td
                  class="Antunes"
                  match="22"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sábado, 26/nov 19:00</td>
                <td data-v-58113781="">Argentina vs México</td>
                <td match="23" contenteditable="false" data-v-58113781="">2-0</td>
                <td
                  class="Midas"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="14Animes"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="moniquita"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="dishadow"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="cerdas"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td class="MO" match="23" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-1
                </td>
                <td
                  class="Madalena"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Paulo Portas"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="André Pereira"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="Not mimi"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Antunes"
                  match="23"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Domingo, 27/nov 10:00</td>
                <td data-v-58113781="">Japão vs Costa Rica</td>
                <td match="24" contenteditable="false" data-v-58113781="">0-1</td>
                <td class="Midas" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="14Animes" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Gabriel" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td
                  class="dishadow"
                  match="24"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="cerdas" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="MO" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="Madalena" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Paulo Portas" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-0
                </td>
                <td class="Not mimi" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="Antunes" match="24" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Domingo, 27/nov 13:00</td>
                <td data-v-58113781="">Bélgica vs Marrocos</td>
                <td match="25" contenteditable="false" data-v-58113781="">0-2</td>
                <td class="Midas" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="14Animes" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Gabriel" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="moniquita" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="dishadow" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="cerdas" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="MO" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-2</td>
                <td class="Madalena" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Paulo Portas" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="André Pereira" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  2-0
                </td>
                <td class="Not mimi" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="Antunes" match="25" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Domingo, 27/nov 16:00</td>
                <td data-v-58113781="">Croácia vs Canadá</td>
                <td match="26" contenteditable="false" data-v-58113781="">4-1</td>
                <td
                  class="Midas"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td class="14Animes" match="26" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td
                  class="Gabriel"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="moniquita"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="dishadow"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="cerdas" match="26" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="MO" match="26" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  2-0
                </td>
                <td
                  class="Madalena"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td class="Paulo Portas" match="26" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="26" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-1
                </td>
                <td
                  class="Not mimi"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td
                  class="Antunes"
                  match="26"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Domingo, 27/nov 19:00</td>
                <td data-v-58113781="">Espanha vs Alemanha</td>
                <td match="27" contenteditable="false" data-v-58113781="">1-1</td>
                <td
                  class="Midas"
                  match="27"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-1
                </td>
                <td class="14Animes" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Gabriel" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td
                  class="moniquita"
                  match="27"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-2
                </td>
                <td
                  class="dishadow"
                  match="27"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-2
                </td>
                <td class="cerdas" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-2</td>
                <td class="MO" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Madalena" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-3</td>
                <td class="Paulo Portas" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td
                  class="André Pereira"
                  match="27"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-2
                </td>
                <td class="Not mimi" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-3</td>
                <td class="Antunes" match="27" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 28/nov 10:00</td>
                <td data-v-58113781="">Camarões vs Sérvia</td>
                <td match="28" contenteditable="false" data-v-58113781="">3-3</td>
                <td class="Midas" match="28" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td
                  class="14Animes"
                  match="28"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td class="Gabriel" match="28" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="moniquita"
                  match="28"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td
                  class="dishadow"
                  match="28"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td
                  class="cerdas"
                  match="28"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td class="MO" match="28" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Madalena" match="28" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td
                  class="Paulo Portas"
                  match="28"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td class="André Pereira" match="28" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-1
                </td>
                <td
                  class="Not mimi"
                  match="28"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td class="Antunes" match="28" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 28/nov 13:00</td>
                <td data-v-58113781="">Coreia do Sul vs Gana</td>
                <td match="29" contenteditable="false" data-v-58113781="">2-3</td>
                <td class="Midas" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="14Animes"
                  match="29"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="Gabriel" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="moniquita"
                  match="29"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="dishadow" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="cerdas" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="MO" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td class="Madalena" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Paulo Portas" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  3-1
                </td>
                <td class="Not mimi" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1</td>
                <td class="Antunes" match="29" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 28/nov 16:00</td>
                <td data-v-58113781="">Brasil vs Suíça</td>
                <td match="30" contenteditable="false" data-v-58113781="">1-0</td>
                <td
                  class="Midas"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-2
                </td>
                <td
                  class="14Animes"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="moniquita"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="dishadow"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="cerdas"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td class="MO" match="30" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Madalena"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="Paulo Portas"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-0
                </td>
                <td
                  class="André Pereira"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Not mimi"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <td
                  class="Antunes"
                  match="30"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Segunda, 28/nov 19:00</td>
                <td data-v-58113781="">Portugal vs Uruguai</td>
                <td match="31" contenteditable="false" data-v-58113781="">2-0</td>
                <td class="Midas" match="31" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="14Animes"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Gabriel"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="moniquita"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <td class="dishadow" match="31" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <td
                  class="cerdas"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td class="MO" match="31" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset"></td>
                <td
                  class="Madalena"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  2-1
                </td>
                <td
                  class="Paulo Portas"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td class="André Pereira" match="31" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-3
                </td>
                <td class="Not mimi" match="31" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="Antunes"
                  match="31"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-0
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 29/nov 10:00</td>
                <td data-v-58113781="">Equador vs Senegal</td>
                <td match="32" contenteditable="false" data-v-58113781="">1-2</td>
                <td class="Midas" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="14Animes" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="Gabriel"
                  match="32"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="moniquita" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="dishadow" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td
                  class="cerdas"
                  match="32"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="MO" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="Madalena" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Paulo Portas" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="Not mimi" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Antunes" match="32" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 29/nov 13:00</td>
                <td data-v-58113781="">Países Baixos vs Catar</td>
                <td match="33" contenteditable="false" data-v-58113781="">2-0</td>
                <td
                  class="Midas"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="14Animes"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="Gabriel"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  4-0
                </td>
                <td
                  class="moniquita"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="dishadow"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="cerdas"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td class="MO" match="33" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  4-0
                </td>
                <td
                  class="Madalena"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  3-0
                </td>
                <td
                  class="Paulo Portas"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td class="André Pereira" match="33" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-0
                </td>
                <td
                  class="Not mimi"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <td
                  class="Antunes"
                  match="33"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  2-0
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 29/nov 16:00</td>
                <td data-v-58113781="">Irão vs Estados Unidos</td>
                <td match="34" contenteditable="false" data-v-58113781="">0-1</td>
                <td class="Midas" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="14Animes" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="Gabriel" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="dishadow" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">3-1</td>
                <td class="cerdas" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="MO" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  1-2
                </td>
                <td
                  class="Madalena"
                  match="34"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Paulo Portas"
                  match="34"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td class="André Pereira" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-0
                </td>
                <td class="Not mimi" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="Antunes" match="34" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Terça, 29/nov 19:00</td>
                <td data-v-58113781="">País de Gales vs Inglaterra</td>
                <td match="35" contenteditable="false" data-v-58113781="">0-3</td>
                <td
                  class="Midas"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="14Animes" match="35" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="Gabriel"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-3
                </td>
                <td
                  class="moniquita"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="dishadow"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td class="cerdas" match="35" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td class="MO" match="35" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  0-2
                </td>
                <td
                  class="Madalena"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Paulo Portas"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="André Pereira"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="Not mimi"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-3
                </td>
                <td
                  class="Antunes"
                  match="35"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 30/nov 10:00</td>
                <td data-v-58113781="">Austrália vs Dinamarca</td>
                <td match="36" contenteditable="false" data-v-58113781="">1-0</td>
                <td class="Midas" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="14Animes" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <td class="Gabriel" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="moniquita" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="dishadow" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="cerdas" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="MO" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="Madalena" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Paulo Portas" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-0
                </td>
                <td class="Not mimi" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="Antunes" match="36" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 30/nov 13:00</td>
                <td data-v-58113781="">Tunísia vs França</td>
                <td match="37" contenteditable="false" data-v-58113781="">1-0</td>
                <td class="Midas" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="14Animes" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Gabriel" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-3</td>
                <td class="moniquita" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="dishadow" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="cerdas" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="MO" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Madalena" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Paulo Portas" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="André Pereira" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="Not mimi" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="Antunes" match="37" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 30/nov 16:00</td>
                <td data-v-58113781="">Arábia Saudita vs México</td>
                <td match="38" contenteditable="false" data-v-58113781="">1-2</td>
                <td
                  class="Midas"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-2
                </td>
                <td
                  class="14Animes"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="Gabriel"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="moniquita"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td class="dishadow" match="38" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="cerdas" match="38" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="MO" match="38" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(168, 255, 168)">
                  1-2
                </td>
                <td
                  class="Madalena"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-2
                </td>
                <td class="Paulo Portas" match="38" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="Not mimi" match="38" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-</td>
                <td
                  class="Antunes"
                  match="38"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-2
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quarta, 30/nov 19:00</td>
                <td data-v-58113781="">Polônia vs Argentina</td>
                <td match="39" contenteditable="false" data-v-58113781="">0-2</td>
                <td
                  class="Midas"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td
                  class="14Animes"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Gabriel"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="moniquita"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="dishadow"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="cerdas"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="MO" match="39" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <td
                  class="Madalena"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="Paulo Portas"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="André Pereira"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td
                  class="Not mimi"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-3
                </td>
                <td
                  class="Antunes"
                  match="39"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 01/dez 10:00</td>
                <td data-v-58113781="">Canadá vs Marrocos</td>
                <td match="40" contenteditable="false" data-v-58113781="">1-2</td>
                <td class="Midas" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td
                  class="14Animes"
                  match="40"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="Gabriel" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td class="moniquita" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="dishadow" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="cerdas" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="MO" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="Madalena"
                  match="40"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="Paulo Portas" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td class="André Pereira" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-0
                </td>
                <td class="Not mimi" match="40" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="Antunes"
                  match="40"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 01/dez 13:00</td>
                <td data-v-58113781="">Croácia vs Bélgica</td>
                <td match="41" contenteditable="false" data-v-58113781="">0-0</td>
                <td
                  class="Midas"
                  match="41"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-1
                </td>
                <td class="14Animes" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Gabriel" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="moniquita" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="dishadow" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="cerdas" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="MO" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="Madalena" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Paulo Portas" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="André Pereira" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-2
                </td>
                <td class="Not mimi" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="Antunes" match="41" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 01/dez 16:00</td>
                <td data-v-58113781="">Costa Rica vs Alemanha</td>
                <td match="42" contenteditable="false" data-v-58113781="">2-4</td>
                <td class="Midas" match="42" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td
                  class="14Animes"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Gabriel"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td
                  class="moniquita"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-4
                </td>
                <td
                  class="dishadow"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-6
                </td>
                <td
                  class="cerdas"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td class="MO" match="42" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  0-4
                </td>
                <td
                  class="Madalena"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="Paulo Portas"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-2
                </td>
                <td
                  class="André Pereira"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-4
                </td>
                <td
                  class="Not mimi"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-6
                </td>
                <td
                  class="Antunes"
                  match="42"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-4
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Quinta, 01/dez 19:00</td>
                <td data-v-58113781="">Japão vs Espanha</td>
                <td match="43" contenteditable="false" data-v-58113781="">2-1</td>
                <td class="Midas" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="14Animes" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Gabriel" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="moniquita" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="dishadow" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-3</td>
                <td class="cerdas" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-3</td>
                <td class="MO" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="Madalena" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Paulo Portas" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="André Pereira" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-2
                </td>
                <td class="Not mimi" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <td class="Antunes" match="43" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 02/dez 10:00</td>
                <td data-v-58113781="">Coreia do Sul vs Portugal</td>
                <td match="44" contenteditable="false" data-v-58113781="">2-1</td>
                <td class="Midas" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-3</td>
                <td class="14Animes" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="Gabriel" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-4</td>
                <td class="moniquita" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="dishadow" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-4</td>
                <td class="cerdas" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="MO" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-1</td>
                <td class="Madalena" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <td class="Paulo Portas" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="André Pereira" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-0
                </td>
                <td class="Not mimi" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="Antunes" match="44" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-2</td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 02/dez 13:00</td>
                <td data-v-58113781="">Gana vs Uruguai</td>
                <td match="45" contenteditable="false" data-v-58113781="">0-2</td>
                <td
                  class="Midas"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="14Animes" match="45" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-1</td>
                <td class="Gabriel" match="45" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-0</td>
                <td
                  class="moniquita"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="dishadow"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td
                  class="cerdas"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td class="MO" match="45" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  1-2
                </td>
                <td
                  class="Madalena"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="Paulo Portas"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  0-2
                </td>
                <td
                  class="André Pereira"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="Not mimi"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-3
                </td>
                <td
                  class="Antunes"
                  match="45"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 02/dez 16:00</td>
                <td data-v-58113781="">Sérvia vs Suíça</td>
                <td match="46" contenteditable="false" data-v-58113781="">2-3</td>
                <td
                  class="Midas"
                  match="46"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-5
                </td>
                <td class="14Animes" match="46" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <td class="Gabriel" match="46" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-0</td>
                <td
                  class="moniquita"
                  match="46"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="dishadow" match="46" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="cerdas" match="46" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-1</td>
                <td class="MO" match="46" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: rgb(255, 255, 167)">
                  0-1
                </td>
                <td
                  class="Madalena"
                  match="46"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td class="Paulo Portas" match="46" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  1-1
                </td>
                <td
                  class="André Pereira"
                  match="46"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  1-2
                </td>
                <td
                  class="Not mimi"
                  match="46"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <td
                  class="Antunes"
                  match="46"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(255, 255, 167)"
                >
                  0-1
                </td>
                <!--v-if--><!--v-if-->
              </tr>
              <tr data-v-58113781="">
                <td data-v-58113781="">Sexta, 02/dez 19:00</td>
                <td data-v-58113781="">Camarões vs Brasil</td>
                <td match="47" contenteditable="false" data-v-58113781="">1-0</td>
                <td class="Midas" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">0-0</td>
                <td class="14Animes" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td
                  class="Gabriel"
                  match="47"
                  contenteditable="false"
                  title="As apostas para este jogo já fecharam!"
                  data-v-58113781=""
                  style="cursor: not-allowed; background-color: rgb(168, 255, 168)"
                >
                  1-0
                </td>
                <td class="moniquita" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-4</td>
                <td class="dishadow" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-5</td>
                <td class="cerdas" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-4</td>
                <td class="MO" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">2-2</td>
                <td class="Madalena" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-3</td>
                <td class="Paulo Portas" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="André Pereira" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">
                  0-2
                </td>
                <td class="Not mimi" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-4</td>
                <td class="Antunes" match="47" contenteditable="false" title="As apostas para este jogo já fecharam!" data-v-58113781="" style="cursor: not-allowed; background-color: unset">1-2</td>
                <!--v-if--><!--v-if-->
              </tr>
            </tbody>
            <tfoot data-v-58113781="">
              <tr class="table100-head" data-v-58113781="">
                <th colspan="3" data-v-58113781="">Scores</th>
                <th data-v-58113781="">35</th>
                <th data-v-58113781="">26</th>
                <th data-v-58113781="">30</th>
                <th data-v-58113781="">31</th>
                <th data-v-58113781="">32</th>
                <th data-v-58113781="">30</th>
                <th data-v-58113781="">26</th>
                <th data-v-58113781="">31</th>
                <th data-v-58113781="">39</th>
                <th data-v-58113781="">24</th>
                <th data-v-58113781="">20</th>
                <th data-v-58113781="">27</th>
              </tr>
            </tfoot>
          </table>
          <!--v-if-->
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
      sortedScore: [],
      leaderboardFaseGrupos: [
        {
          name: "Midas",
          score: 45,
        },
        {
          name: "dishadow",
          score: 41,
        },
        {
          name: "cerdas",
          score: 38,
        },
        {
          name: "Gabriel",
          score: 37,
        },
        {
          name: "Madalena",
          score: 32,
        },
        {
          name: "14Animes",
          score: 32,
        },
        {
          name: "moniquita",
          score: 31,
        },
        {
          name: "MO",
          score: 30,
        },
        {
          name: "Antunes",
          score: 27,
        },
        {
          name: "André Pereira",
          score: 24,
        },
        {
          name: "Not mimi",
          score: 20,
        },
      ],
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
        body: JSON.stringify({ name: this.username, score: 0, individual: [] }),
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
      if (this.matches[match].bets[name] == undefined) return 0;
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
