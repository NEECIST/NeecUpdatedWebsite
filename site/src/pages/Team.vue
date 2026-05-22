<template>
  <div class="team-app-modern">
    <!-- Hero Section -->
    <div class="team-hero">
      <div class="team-hero-overlay">
        <h1 class="team-hero-title">EQUIPA</h1>
        <h2 class="team-hero-subtitle">2025/2026</h2>
      </div>
    </div>
    
    <!-- Content -->
    <div class="team-content">
      <!-- Direção -->
      <div class="team-section">
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

      <!-- Outras Equipas -->
      <div class="team-section" v-for="team in teamsData" :key="team.title">
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
};
</script>

<style scoped>
@import url('https://fonts.googleapis.com/css2?family=Courier+Prime:wght@400;700&family=IBM+Plex+Mono:wght@400;700&family=Montserrat:wght@400;700;900&display=swap');

.team-app-modern {
  background-color: #030a13;
  color: #FFF4E8;
  min-height: 100vh;
  font-family: 'Courier Prime', 'Courier New', Courier, monospace;
}

/* Header/Hero Section */
.team-hero {
  height: 30vh;
  min-height: 250px;
  background-color: #0d1b2a; /* Pure background color instead of image */
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

.team-content {
  padding: 40px 10%;
  max-width: 1400px;
  margin: 0 auto;
}

.team-section {
  margin-bottom: 60px;
}

.section-header {
  display: flex;
  align-items: center;
  margin-bottom: 30px;
}

.vertical-bar {
  display: inline-block;
  width: 4px;
  height: 28px;
  background-color: #00e5ff;
  border-radius: 4px;
  margin-right: 15px;
  /* Removed glow effect */
}

.section-header h2 {
  font-size: 2rem;
  font-weight: 700;
  margin: 0;
  color: #FFF4E8;
}

.members-grid {
  display: grid;
  grid-template-columns: repeat(4, 1fr);
  gap: 40px 20px;
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
}
@media (max-width: 480px) {
  .members-grid {
    grid-template-columns: repeat(1, 1fr);
  }
}

.member-card {
  display: flex;
  flex-direction: column;
  align-items: center;
  text-align: center;
}

/* Plain solid color rectangle for photo */
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
