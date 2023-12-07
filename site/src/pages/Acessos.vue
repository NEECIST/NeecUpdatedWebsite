<template>
  <div id="app1">
    <h1>Acessos Sede NEECIST</h1>
    <div id="box_div">
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>Date</th>
            <th>Time</th>
            <th>Status</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(item, index) in logs" :key="item.id" :class="{ 'highlight-row': item.status_code === 'Incorrect', 'even-row': index % 2 === 0, 'odd-row': index % 2 !== 0 }">
            <td>{{ item.name }}</td>
            <td>{{ item.date }}</td>
            <td>{{ item.time }}</td>
            <td>{{ item.status_code }}</td>
          </tr>
        </tbody>
      </table>
    </div>
    <a class="buttons" :href="'http://localhost:8080/acessos_sede?page=' + page_before">Anterior</a>
    <a class="buttons" :href="'http://localhost:8080/acessos_sede?page=' + page">Mais registos</a>
    <div v-if="error">
      <p>Error fetching data: {{ error }}</p>
    </div>
  </div>
</template>

<script>
export default {
  name: "acessos-page",
  data() {
    return {
      logs: [],
      error: null,
      page: 0,
      page_before: 0,
    };
  },
  methods: {
    fetchData(page) {
      fetch("http://neecdoor.neec.midas-cloud.xyz/records?page=" + page)
        .then((response) => response.json())
        .then((data) => {
          this.logs = data;
          this.error = null;
        })
        .catch((error) => {
          console.error("Error fetching data:", error);
          this.error = error.message || "Unknown error";
          this.logs = [];
        });
    },
  },
  created() {
    // get params from url
    const urlParams = new URLSearchParams(window.location.search);
    const page = urlParams.get("page");
    if (page === null || page === "0") {
      this.fetchData(0);
      this.page = 1;
      this.page_before = 0;
    } else {
      this.fetchData(page);
      this.page = parseInt(page) + 1;
      this.page_before = parseInt(page) - 1;
    }
  },
};
</script>

<style>
#box_div {
  margin-inline: 500px;
  margin-bottom: 35px;
}

#app1 {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;
  margin-block: 60px;
}

h1 {
  font-size: 2em;
  margin-bottom: 20px;
}

button {
  padding: 10px 20px;
  font-size: 1em;
  background-color: #3498db;
  color: #fff;
  border: none;
  cursor: pointer;
}

button:hover {
  background-color: #2980b9;
}

pre {
  white-space: pre-wrap;
}
table {
  width: 100%;
  border-collapse: collapse;
  margin-top: 20px;
}

th,
td {
  border: 1px solid #ddd;
  padding: 8px;
  text-align: left;
}

th {
  background-color: hsl(199 76% 58% / 1);
  color: white;
}

.even-row {
  background-color: #f9f9f9; /* Light gray background for even rows */
}

.odd-row {
  background-color: #ffffff; /* White background for odd rows */
}
.highlight-row {
  background-color: #ffe6e6; /* Soft red background */
}

a.buttons {
  margin-inline: 25px;
  background-color: #43b2e5;
  color: white;
  padding: 0.3rem;
  border-radius: 10px;
}

@media screen and (max-width: 600px) {
  #box_div {
    margin-inline: 0px;
  }
}
</style>
