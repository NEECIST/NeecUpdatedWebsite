<template>
  <div class="neecathon-page">

    <!-- ═══════════════════════════════ HERO ═══════════════════════════════ -->
    <section class="neecathon-hero">
      <div class="neecathon-hero__overlay">
        <h1 class="neecathon-hero__title">NEECathon</h1>
        <p class="neecathon-hero__subtitle">Uma competição xyz</p>
      </div>
    </section>

    <!-- ══════════════════════════ INFO CARD ════════════════════════════════ -->
    <section class="neecathon-section neecathon-section--mid">
      <div class="neecathon-section__content">
        <div class="info-card">
          <h2 class="info-card__title">O que é; onde; quando, como</h2>
          <div class="info-card__body">
            <p>
              <span class="highlight">NEECathon</span> isto e aquilo<br>
              descrição<br>
              filler <strong>parte importante</strong><br>
              onde quando como
            </p>
          </div>
          <div class="info-card__buttons">
            <button class="pill-button">X Edições</button>
            <button class="pill-button">Y prémios dados</button>
            <button class="pill-button">Z ?</button>
          </div>
        </div>
      </div>
    </section>

    <!-- ══════════════════════════ EDITIONS ═════════════════════════════════ -->
    <section class="neecathon-section neecathon-section--dark">
      <div class="neecathon-section__content neecathon-section__content--wide">
        <h2 class="section-title">EDIÇÕES</h2>

        <div class="editions-carousel" aria-label="Edições NEECathon">
          <button class="carousel-arrow" @click="prevEdition" aria-label="Anterior">&#8249;</button>

          <div class="carousel-track">
            <div
              v-for="(edition, index) in visibleEditions"
              :key="edition.year"
              class="edition-card"
              :class="{ 'edition-card--active': index === 1, 'edition-card--side': index !== 1 }"
            >
              <div class="edition-card__image">
                <span class="edition-card__year">{{ edition.year }}</span>
              </div>
            </div>
          </div>

          <button class="carousel-arrow" @click="nextEdition" aria-label="Próxima">&#8250;</button>
        </div>
      </div>
    </section>

    <!-- ══════════════════════════ 2026 CARD ════════════════════════════════ -->
    <section class="neecathon-section neecathon-section--mid">
      <div class="neecathon-section__content">
        <div class="info-card">
          <h2 class="info-card__title">NEECathon 2026</h2>
          <div class="info-card__rows">
            <div class="info-card__row">
              <span class="info-card__label">Data:</span>
              <span>placeholder data</span>
            </div>
            <div class="info-card__row">
              <span class="info-card__label">Preço:</span>
              <span>placeholder preço</span>
            </div>
            <div class="info-card__row">
              <span class="info-card__label">Inscrições:</span>
              <span>placeholder inscrições</span>
            </div>
          </div>
          <div class="info-card__site-row">
            <span class="info-card__label">Site da competição:</span>
            <button class="pill-button pill-button--dark">Disponível em breve</button>
          </div>
        </div>
      </div>
    </section>

    <!-- ══════════════════════════ MAIS INFO ════════════════════════════════ -->
    <section class="neecathon-section neecathon-section--mid">
      <div class="neecathon-section__content">
        <h2 class="section-title section-title--left">MAIS INFO:</h2>
        <ul class="more-info-list">
          <li>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</li>
          <li>Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.</li>
          <li>Ut enim ad minim veniam, quis nostrud exercitation ullamco.</li>
        </ul>
      </div>
    </section>

  </div>
</template>

<script>
export default {
  name: "neecathon-page",
  data() {
    return {
      centerIndex: 1,
      editions: [
        { year: "2025" },
        { year: "2024" },
        { year: "2023" },
      ],
    };
  },
  computed: {
    visibleEditions() {
      const total = this.editions.length;
      return [
        this.editions[(this.centerIndex - 1 + total) % total],
        this.editions[this.centerIndex],
        this.editions[(this.centerIndex + 1) % total],
      ];
    },
  },
  methods: {
    nextEdition() {
      this.centerIndex = (this.centerIndex + 1) % this.editions.length;
    },
    prevEdition() {
      this.centerIndex =
        (this.centerIndex - 1 + this.editions.length) % this.editions.length;
    },
  },
};
</script>

<style scoped>
@import url('https://fonts.googleapis.com/css2?family=Anonymous+Pro:wght@400;700&display=swap');

/* ── BASE ─────────────────────────────────────────────────── */
.neecathon-page {
  background-color: #1a3a52;
  color: #fff;
  font-family: 'Anonymous Pro', 'Courier New', monospace;
  min-height: 100vh;
}

.neecathon-page,
.neecathon-page * {
  box-sizing: border-box;
}

/* ── HERO ─────────────────────────────────────────────────── */
.neecathon-hero {
  height: calc(60vh - 60px);
  min-height: 380px;
  background-color: #0d1b2a;
  position: relative;
  display: flex;
  align-items: center;
  justify-content: center;
}

.neecathon-hero__overlay {
  text-align: center;
  z-index: 2;
}

.neecathon-hero__title {
  font-size: clamp(3.5rem, 9vw, 6.5rem);
  font-weight: 700;
  color: #fff;
  margin: 0;
  letter-spacing: 3px;
  text-shadow: 0 2px 16px rgba(0, 0, 0, 0.55);
}

.neecathon-hero__subtitle {
  font-size: clamp(1rem, 2.5vw, 1.5rem);
  color: #c8dce8;
  margin: 1rem 0 0;
  letter-spacing: 1px;
}

/* ── SECTIONS ─────────────────────────────────────────────── */
.neecathon-section {
  display: flex;
  justify-content: center;
  padding: 64px 8vw;
  width: 100%;
}

.neecathon-section--mid {
  background-color: #1a3a52;
}

.neecathon-section--dark {
  background-color: #0A2342;
  padding-top: 0;
}

.neecathon-section__content {
  max-width: 820px;
  width: 100%;
}

.neecathon-section__content--wide {
  max-width: 1200px;
}

/* ── INFO CARD ────────────────────────────────────────────── */
.info-card {
  background-color: #b8d4e8;
  border-radius: 16px;
  padding: 2.5rem 3rem;
  color: #000;
}

.info-card__title {
  font-size: clamp(1.3rem, 2.5vw, 1.8rem);
  font-weight: 700;
  margin: 0 0 1.5rem;
  color: #000;
  letter-spacing: 0.5px;
}

.info-card__body {
  margin-bottom: 2rem;
}

.info-card__body p {
  font-size: 1rem;
  line-height: 2;
  margin: 0;
}

.highlight {
  color: #1E6091;
  font-weight: 700;
}

/* Buttons */
.info-card__buttons {
  display: flex;
  gap: 1rem;
  flex-wrap: wrap;
}

.pill-button {
  background-color: #0A2342;
  color: #fff;
  border: none;
  padding: 0.65rem 1.6rem;
  border-radius: 30px;
  font-family: inherit;
  font-size: 0.95rem;
  font-weight: 700;
  cursor: pointer;
  transition: background 0.2s, transform 0.15s;
}

.pill-button:hover {
  background-color: #1E6091;
  transform: translateY(-2px);
}

.pill-button--dark {
  background-color: #0A2342;
}

/* 2026 card rows */
.info-card__rows {
  display: flex;
  flex-direction: column;
  gap: 1.1rem;
  margin-bottom: 1.5rem;
}

.info-card__row {
  display: flex;
  gap: 1.5rem;
  align-items: baseline;
}

.info-card__label {
  color: #1E6091;
  font-weight: 700;
  min-width: 115px;
  flex-shrink: 0;
}

.info-card__site-row {
  display: flex;
  align-items: center;
  gap: 1.5rem;
  padding-top: 1.5rem;
  border-top: 1px solid rgba(0, 0, 0, 0.18);
  flex-wrap: wrap;
}

/* ── EDITIONS ─────────────────────────────────────────────── */
.section-title {
  font-size: clamp(1.6rem, 3vw, 2.2rem);
  font-weight: 700;
  letter-spacing: 3px;
  color: #fff;
  text-align: center;
  padding: 2rem 0 2.5rem;
  margin: 0;
}

.section-title--left {
  text-align: left;
  letter-spacing: 1px;
  margin-bottom: 1.5rem;
}

.editions-carousel {
  display: flex;
  align-items: center;
  justify-content: center;
  gap: 1.5rem;
}

.carousel-arrow {
  background: transparent;
  border: none;
  color: #fff;
  font-size: 3.5rem;
  line-height: 1;
  cursor: pointer;
  padding: 0 0.3rem;
  flex-shrink: 0;
  transition: color 0.2s, transform 0.15s;
}

.carousel-arrow:hover {
  color: #6FE7B8;
  transform: scale(1.15);
}

.carousel-track {
  display: flex;
  align-items: center;
  gap: 1.5rem;
}

.edition-card {
  transition: all 0.3s ease;
  flex-shrink: 0;
}

.edition-card--active {
  transform: scale(1.08);
  opacity: 1;
  z-index: 2;
}

.edition-card--side {
  transform: scale(0.88);
  opacity: 0.45;
  z-index: 1;
}

.edition-card__image {
  width: 300px;
  height: 210px;
  background: linear-gradient(135deg, #1E6091 0%, #0A2342 100%);
  border-radius: 10px;
  display: flex;
  align-items: flex-start;
  justify-content: flex-start;
  padding: 1rem 1.2rem;
  position: relative;
}

.edition-card--side .edition-card__image {
  width: 260px;
  height: 180px;
}

.edition-card__year {
  font-size: 1.4rem;
  font-weight: 700;
  color: #fff;
  text-shadow: 0 1px 6px rgba(0, 0, 0, 0.4);
}

/* ── MORE INFO ────────────────────────────────────────────── */
.more-info-list {
  list-style: none;
  padding: 0;
  margin: 0;
}

.more-info-list li {
  color: #fff;
  font-size: 1rem;
  line-height: 1.7;
  padding: 0.5rem 0 0.5rem 1.8rem;
  position: relative;
}

.more-info-list li::before {
  content: '•';
  position: absolute;
  left: 0;
  color: #6FE7B8;
  font-size: 1.3rem;
  line-height: 1.45;
}

/* ── RESPONSIVE ───────────────────────────────────────────── */
@media (max-width: 900px) {
  .edition-card__image {
    width: 220px;
    height: 155px;
  }

  .edition-card--side .edition-card__image {
    width: 180px;
    height: 130px;
  }
}

@media (max-width: 600px) {
  .neecathon-section {
    padding: 48px 24px;
  }

  .info-card {
    padding: 1.5rem 1.2rem;
  }

  .info-card__buttons {
    flex-direction: column;
  }

  .pill-button {
    width: 100%;
    text-align: center;
  }

  .edition-card__image {
    width: 160px;
    height: 115px;
  }

  .edition-card--side .edition-card__image {
    width: 120px;
    height: 90px;
  }

  .carousel-arrow {
    font-size: 2.5rem;
  }
}
</style>
