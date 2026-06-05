<template>
  <div class="team-app-modern">
    <!-- Hero Section - Full Screen -->
    <div class="fullscreen-section team-hero">
      <div class="team-hero-overlay">
        <h1 class="team-hero-title">EQUIPA</h1>
        <h2 class="team-hero-subtitle">2025/2026</h2>
      </div>
    </div>
    
    <!-- Direção Section -->
    <div class="section-group">
      <!-- Direção Intro - Full Screen -->
      <div class="fullscreen-section section-intro-screen">
        <div class="intro-content">
          <div class="section-header">
            <span class="vertical-bar"></span>
            <h2>Direção</h2>
          </div>
          <div class="intro-text">
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
          </div>
        </div>
      </div>
      
      <!-- Direção Members -->
      <div class="fullscreen-section team-section">
        <div class="section-content">
          <div class="section-header">
            <span class="vertical-bar"></span>
            <h2>Direção</h2>
          </div>
          <div class="members-grid">
            <div class="member-card" v-for="i in 7" :key="'dir-'+i" data-aos="zoom-in">
               <div class="member-photo-placeholder"></div>
               <div class="member-info">
                 <p class="member-name">Nome</p>
                 <p class="member-role" v-if="i===1">Presidente</p>
                 <p class="member-role" v-else-if="i===2">Tesoureira</p>
                 <p class="member-role" v-else-if="i===3 || i===4">Vice-Presidente</p>
                 <p class="member-role" v-else>Vogal</p>
               </div>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- Outras Equipas -->
    <div class="section-group" v-for="team in teamsData" :key="team.title">
      <!-- Team Intro - Full Screen -->
      <div class="fullscreen-section section-intro-screen">
        <div class="intro-content">
          <div class="section-header">
            <span class="vertical-bar"></span>
            <h2>{{ team.title }}</h2>
          </div>
          <div class="intro-text">
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
          </div>
        </div>
      </div>

      <!-- Team Members -->
      <div class="fullscreen-section team-section">
        <div class="section-content">
          <div class="section-header">
            <span class="vertical-bar"></span>
            <h2>{{ team.title }}</h2>
          </div>
          <div class="members-grid">
            <div class="member-card" v-for="i in team.count" :key="team.title+'-'+i" data-aos="zoom-in">
              <div class="member-photo-placeholder"></div>
              <div class="member-info">
                <p class="member-name">Nome</p>
                <p class="member-role" v-if="i===1">Team Leader</p>
                <p class="member-role" v-else >NEECo</p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "team-page",
  data() {
    return {
      teamsData: [
        { title: "Design", count: 12 },
        { title: "NEECIT", count: 12 },
        { title: "Multimédia", count: 12 },
        { title: "Divulgação", count: 12 },
      ],
    };
  },
  methods: {
  },
};
</script>

<style scoped>
@import url('https://fonts.googleapis.com/css2?family=Courier+Prime:wght@400;700&family=IBM+Plex+Mono:wght@400;700&family=Montserrat:wght@400;700;900&display=swap');

.team-app-modern {
  background-color: #030a13;
  color: #FFF4E8;
  font-family: 'Courier Prime', 'Courier New', Courier, monospace;
  scroll-snap-type: y mandatory;
  overflow-y: scroll;
  scrollbar-width: none;
  -ms-overflow-style: none;
}

.team-app-modern::-webkit-scrollbar {
  display: none;
}

/* Full Screen Sections */
.fullscreen-section {
  height: 100vh;
  width: 100%;
  display: flex;
  align-items: center;
  justify-content: center;
  scroll-snap-align: start;
  scroll-snap-stop: always;
}

.section-group {
  display: flex;
  flex-direction: column;
}

.section-group .fullscreen-section {
  margin-bottom: 50vh;
}

/* Hero Section */
.team-hero {
  background-color: #0d1b2a;
  position: relative;
}

.team-hero-overlay {
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  text-align: center;
}

.team-hero-title {
  font-family: 'IBM Plex Mono', monospace;
  font-size: 5rem;
  font-weight: 700;
  color: #FFF4E8;
  margin: 0;
  letter-spacing: 5px;
}

.team-hero-subtitle {
  font-family: 'IBM Plex Mono', monospace;
  font-size: 1.5rem;
  font-weight: 700;
  color: #FFF4E8;
  margin-top: -10px;
  letter-spacing: 2px;
}

/* Intro Screen Section */
.section-intro-screen {
  background-color: #0d1b2a;
}

.intro-content {
  width: 90%;
  max-width: 900px;
  text-align: center;
}

.intro-text {
  margin-top: 40px;
}

.intro-text p {
  font-size: 1.2rem;
  line-height: 1.8;
  color: #b8bcc4;
  font-family: 'Montserrat', sans-serif;
  margin: 0;
}

/* Team Section with Members */
.team-section {
  background-color: #030a13;
}

.section-content {
  width: 90%;
  max-width: 1400px;
  padding: 40px 0;
}

.section-header {
  display: flex;
  align-items: center;
  margin-bottom: 40px;
  justify-content: center;
}

.vertical-bar {
  display: none;
}

.section-header h2 {
  font-size: 4rem;
  font-weight: 700;
  margin: 0;
  color: #FFF4E8;
  letter-spacing: 2px;
}

.members-grid {
  display: grid;
  grid-template-columns: repeat(4, 1fr);
  gap: 60px 40px;
}

@media (max-width: 1024px) {
  .members-grid {
    grid-template-columns: repeat(3, 1fr);
  }
}

@media (max-width: 768px) {
  .members-grid {
    grid-template-columns: repeat(2, 1fr);
  }
  
  .team-hero-title {
    font-size: 3rem;
  }
  
  .section-header h2 {
    font-size: 1.5rem;
  }
  
  .intro-text p {
    font-size: 1rem;
  }
}

@media (max-width: 480px) {
  .members-grid {
    grid-template-columns: repeat(1, 1fr);
  }
  
  .team-hero-title {
    font-size: 2rem;
  }
  
  .section-header h2 {
    font-size: 1.2rem;
  }
  
  .intro-text p {
    font-size: 0.9rem;
  }
}

.member-card {
  display: flex;
  flex-direction: column;
  align-items: center;
  text-align: center;
}

.member-photo-placeholder {
  width: 160px;
  height: 200px;
  background-color: #707478;
  border-radius: 8px;
  margin-bottom: 15px;
}

.member-info {
  display: flex;
  flex-direction: column;
  align-items: center;
}

.member-name {
  margin: 0;
  font-size: 1.1rem;
  font-weight: 700;
  color: #FFF4E8;
}

.member-role {
  margin: 5px 0 0 0;
  font-size: 0.9rem;
  font-weight: 400;
  color: #4080d5;
}
</style>
