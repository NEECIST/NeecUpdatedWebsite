<template>
  <div class="neecathon-page">

    <!-- ═══════════════════════════════ HERO ═══════════════════════════════ -->
    <section class="neecathon-hero">
<<<<<<< HEAD
      <div class="hero-bg"></div>
      <div class="hero-content">
        <div class="hero-accent-line"></div>
        <h1 class="hero-title">NEECathon</h1>
        <p class="hero-subtitle">Uma competição xyz</p>
        <div class="hero-accent-line hero-accent-line--bottom"></div>
      </div>
    </section>

    <!-- ══════════════════════════ INFO SECTION ════════════════════════════ -->
    <section class="ns-section ns-section--mid">
      <div class="ns-content">
        <div class="sharp-card">
          <div class="sharp-card__header">
            <div class="sharp-card__tag">// info</div>
            <h2 class="sharp-card__title">O que é; onde; quando, como</h2>
          </div>
          <div class="sharp-card__body">
            <p>
              <span class="highlight">NEECathon</span> isto e aquilo<br>
              descrição<br>
              filler <strong>parte importante</strong><br>
              onde quando como
            </p>
          </div>
          <div class="sharp-card__footer">
            <button class="sharp-button">X Edições</button>
            <button class="sharp-button">Y prémios dados</button>
            <button class="sharp-button">Z ?</button>
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
          </div>
        </div>
      </div>
    </section>

<<<<<<< HEAD
    <!-- ══════════════════════════ EDITIONS ════════════════════════════════ -->
    <section class="ns-section ns-section--dark">
      <div class="ns-content ns-content--wide">
        <div class="editions-header">
          <div class="editions-header__line"></div>
          <h2 class="editions-header__title">EDIÇÕES</h2>
          <div class="editions-header__line"></div>
        </div>

        <div class="editions-strip">
          <button class="strip-arrow" @click="prevEdition">&#8249;</button>

          <div class="strip-track">
            <div
              v-for="(edition, index) in visibleEditions"
              :key="edition.year + index"
              class="strip-item"
              :class="{
                'strip-item--main':  index === 1,
                'strip-item--side':  index !== 1
              }"
            >
              <div class="strip-item__image">
                <div class="strip-item__overlay"></div>
                <span class="strip-item__year">{{ edition.year }}</span>
                <div class="strip-item__corner strip-item__corner--tl"></div>
                <div class="strip-item__corner strip-item__corner--br"></div>
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
              </div>
            </div>
          </div>

<<<<<<< HEAD
          <button class="strip-arrow" @click="nextEdition">&#8250;</button>
=======
          <button class="carousel-arrow" @click="nextEdition" aria-label="Próxima">&#8250;</button>
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
        </div>
      </div>
    </section>

<<<<<<< HEAD
    <!-- ══════════════════════════ 2026 CARD ═══════════════════════════════ -->
    <section class="ns-section ns-section--mid">
      <div class="ns-content">
        <div class="sharp-card">
          <div class="sharp-card__header">
            <div class="sharp-card__tag">// próxima edição</div>
            <h2 class="sharp-card__title">NEECathon 2026</h2>
          </div>
          <div class="info-grid">
            <div class="info-grid__row">
              <span class="info-grid__label">Data</span>
              <span class="info-grid__sep">—</span>
              <span class="info-grid__value">placeholder data</span>
            </div>
            <div class="info-grid__row">
              <span class="info-grid__label">Preço</span>
              <span class="info-grid__sep">—</span>
              <span class="info-grid__value">placeholder preço</span>
            </div>
            <div class="info-grid__row">
              <span class="info-grid__label">Inscrições</span>
              <span class="info-grid__sep">—</span>
              <span class="info-grid__value">placeholder inscrições</span>
            </div>
          </div>
          <div class="sharp-card__site-row">
            <span class="info-grid__label">Site da competição</span>
            <button class="sharp-button sharp-button--outline">Disponível em breve</button>
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
          </div>
        </div>
      </div>
    </section>

<<<<<<< HEAD
    <!-- ══════════════════════════ MAIS INFO ═══════════════════════════════ -->
    <section class="ns-section ns-section--mid ns-section--last">
      <div class="ns-content">
        <h2 class="more-info-title">MAIS INFO<span class="title-dot">:</span></h2>
        <ul class="more-info-list">
          <li>
            <span class="list-num">01</span>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit.
          </li>
          <li>
            <span class="list-num">02</span>
            Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
          </li>
          <li>
            <span class="list-num">03</span>
            Ut enim ad minim veniam, quis nostrud exercitation ullamco.
          </li>
=======
    <!-- ══════════════════════════ MAIS INFO ════════════════════════════════ -->
    <section class="neecathon-section neecathon-section--mid">
      <div class="neecathon-section__content">
        <h2 class="section-title section-title--left">MAIS INFO:</h2>
        <ul class="more-info-list">
          <li>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</li>
          <li>Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.</li>
          <li>Ut enim ad minim veniam, quis nostrud exercitation ullamco.</li>
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
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
<<<<<<< HEAD
  background-color: #0A2342;
=======
  background-color: #0d1b2a;
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  position: relative;
  display: flex;
  align-items: center;
  justify-content: center;
<<<<<<< HEAD
  overflow: hidden;
}

/* Subtle grid texture */
.hero-bg {
  position: absolute;
  inset: 0;
  background-image:
    linear-gradient(rgba(30, 96, 145, 0.15) 1px, transparent 1px),
    linear-gradient(90deg, rgba(30, 96, 145, 0.15) 1px, transparent 1px);
  background-size: 48px 48px;
}

.hero-content {
  position: relative;
  z-index: 2;
  text-align: center;
  padding: 0 2rem;
}

.hero-accent-line {
  width: 80px;
  height: 3px;
  background-color: #6FE7B8;
  margin: 0 auto 1.5rem;
}

.hero-accent-line--bottom {
  margin: 1.5rem auto 0;
}

.hero-title {
=======
}

.neecathon-hero__overlay {
  text-align: center;
  z-index: 2;
}

.neecathon-hero__title {
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  font-size: clamp(3.5rem, 9vw, 6.5rem);
  font-weight: 700;
  color: #fff;
  margin: 0;
<<<<<<< HEAD
  letter-spacing: 6px;
}

.hero-subtitle {
  font-size: clamp(0.9rem, 2vw, 1.2rem);
  color: #6FE7B8;
  margin: 0.8rem 0 0;
  letter-spacing: 3px;
  text-transform: uppercase;
}

/* ── SECTIONS ─────────────────────────────────────────────── */
.ns-section {
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  display: flex;
  justify-content: center;
  padding: 64px 8vw;
  width: 100%;
}

<<<<<<< HEAD
.ns-section--mid  { background-color: #1a3a52; }
.ns-section--dark { background-color: #0A2342; padding-top: 0; }
.ns-section--last { padding-bottom: 80px; }

.ns-content {
=======
.neecathon-section--mid {
  background-color: #1a3a52;
}

.neecathon-section--dark {
  background-color: #0A2342;
  padding-top: 0;
}

.neecathon-section__content {
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  max-width: 820px;
  width: 100%;
}

<<<<<<< HEAD
.ns-content--wide {
  max-width: 1200px;
}

/* ── SHARP CARD ───────────────────────────────────────────── */
.sharp-card {
  background-color: #b8d4e8;
  border-radius: 0;
  border-left: 4px solid #1E6091;
  padding: 0;
  color: #000;
  overflow: hidden;
}

.sharp-card__header {
  padding: 1.8rem 2.5rem 1.2rem;
  border-bottom: 1px solid rgba(0, 0, 0, 0.12);
}

.sharp-card__tag {
  font-size: 0.75rem;
  color: #1E6091;
  letter-spacing: 2px;
  text-transform: uppercase;
  margin-bottom: 0.6rem;
  font-weight: 700;
}

.sharp-card__title {
  font-size: clamp(1.2rem, 2.5vw, 1.7rem);
  font-weight: 700;
  margin: 0;
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  color: #000;
  letter-spacing: 0.5px;
}

<<<<<<< HEAD
.sharp-card__body {
  padding: 1.8rem 2.5rem;
}

.sharp-card__body p {
=======
.info-card__body {
  margin-bottom: 2rem;
}

.info-card__body p {
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  font-size: 1rem;
  line-height: 2;
  margin: 0;
}

.highlight {
  color: #1E6091;
  font-weight: 700;
}

<<<<<<< HEAD
.sharp-card__footer {
  padding: 1.2rem 2.5rem 1.8rem;
  display: flex;
  gap: 1rem;
  flex-wrap: wrap;
  border-top: 1px solid rgba(0, 0, 0, 0.12);
}

/* ── SHARP BUTTONS ────────────────────────────────────────── */
.sharp-button {
  background-color: #0A2342;
  color: #fff;
  border: none;
  border-radius: 0;
  padding: 0.6rem 1.6rem;
  font-family: inherit;
  font-size: 0.9rem;
  font-weight: 700;
  cursor: pointer;
  letter-spacing: 1px;
  text-transform: uppercase;
  transition: background 0.2s, transform 0.1s;
  border-bottom: 2px solid #1E6091;
}

.sharp-button:hover {
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  background-color: #1E6091;
  transform: translateY(-2px);
}

<<<<<<< HEAD
.sharp-button--outline {
  background-color: transparent;
  border: 2px solid #0A2342;
  color: #0A2342;
}

.sharp-button--outline:hover {
  background-color: #0A2342;
  color: #fff;
}

/* ── INFO GRID (2026 card) ────────────────────────────────── */
.info-grid {
  padding: 1.8rem 2.5rem;
  display: flex;
  flex-direction: column;
  gap: 0;
}

.info-grid__row {
  display: flex;
  align-items: baseline;
  gap: 1rem;
  padding: 0.9rem 0;
  border-bottom: 1px solid rgba(0, 0, 0, 0.08);
}

.info-grid__row:last-child {
  border-bottom: none;
}

.info-grid__label {
  color: #1E6091;
  font-weight: 700;
  min-width: 110px;
  flex-shrink: 0;
  letter-spacing: 0.5px;
  text-transform: uppercase;
  font-size: 0.85rem;
}

.info-grid__sep {
  color: #1E6091;
  flex-shrink: 0;
}

.info-grid__value {
  color: #000;
}

.sharp-card__site-row {
  display: flex;
  align-items: center;
  gap: 1.5rem;
  padding: 1.2rem 2.5rem 1.8rem;
  border-top: 1px solid rgba(0, 0, 0, 0.12);
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  flex-wrap: wrap;
}

/* ── EDITIONS ─────────────────────────────────────────────── */
<<<<<<< HEAD
.editions-header {
  display: flex;
  align-items: center;
  gap: 1.5rem;
  padding: 2.5rem 0 2.5rem;
}

.editions-header__line {
  flex: 1;
  height: 1px;
  background-color: rgba(255, 255, 255, 0.2);
}

.editions-header__title {
  font-size: clamp(1.4rem, 3vw, 2rem);
  font-weight: 700;
  letter-spacing: 6px;
  color: #fff;
  margin: 0;
  white-space: nowrap;
}

.editions-strip {
  display: flex;
  align-items: center;
  gap: 0;
}

.strip-arrow {
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  background: transparent;
  border: none;
  color: #fff;
  font-size: 3.5rem;
  line-height: 1;
  cursor: pointer;
<<<<<<< HEAD
  padding: 0 1rem;
  flex-shrink: 0;
  transition: color 0.2s, transform 0.15s;
  z-index: 2;
}

.strip-arrow:hover {
=======
  padding: 0 0.3rem;
  flex-shrink: 0;
  transition: color 0.2s, transform 0.15s;
}

.carousel-arrow:hover {
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
  color: #6FE7B8;
  transform: scale(1.15);
}

<<<<<<< HEAD
.strip-track {
  display: flex;
  align-items: stretch;
  flex: 1;
  overflow: hidden;
  gap: 4px;
}

.strip-item {
  transition: all 0.35s ease;
  flex-shrink: 0;
  position: relative;
}

.strip-item--main {
  flex: 2;
  opacity: 1;
}

.strip-item--side {
  flex: 1;
  opacity: 0.4;
}

.strip-item__image {
  width: 100%;
  height: 280px;
  background: linear-gradient(160deg, #1E6091 0%, #0A2342 60%, #0d2235 100%);
  position: relative;
  overflow: hidden;
  display: flex;
  align-items: flex-end;
  justify-content: flex-start;
}

.strip-item--main .strip-item__image {
  height: 320px;
}

.strip-item__overlay {
  position: absolute;
  inset: 0;
  background: linear-gradient(to top, rgba(10, 35, 66, 0.7) 0%, transparent 60%);
}

.strip-item__year {
  position: relative;
  z-index: 2;
  font-size: 2rem;
  font-weight: 700;
  color: #fff;
  letter-spacing: 3px;
  padding: 1rem 1.2rem;
}

.strip-item--side .strip-item__year {
  font-size: 1.3rem;
}

/* Sharp corner decorations on active card */
.strip-item__corner {
  position: absolute;
  width: 16px;
  height: 16px;
  z-index: 3;
}

.strip-item--side .strip-item__corner {
  display: none;
}

.strip-item__corner--tl {
  top: 8px;
  left: 8px;
  border-top: 2px solid #6FE7B8;
  border-left: 2px solid #6FE7B8;
}

.strip-item__corner--br {
  bottom: 8px;
  right: 8px;
  border-bottom: 2px solid #6FE7B8;
  border-right: 2px solid #6FE7B8;
}

/* ── MORE INFO ────────────────────────────────────────────── */
.more-info-title {
  font-size: clamp(1.4rem, 3vw, 2rem);
  font-weight: 700;
  letter-spacing: 2px;
  color: #fff;
  margin: 0 0 2rem;
}

.title-dot {
  color: #6FE7B8;
}

.more-info-list {
  list-style: none;
  padding: 0;
  margin: 0;
}

.more-info-list li {
  display: flex;
  align-items: baseline;
  gap: 1.5rem;
  color: #fff;
  font-size: 1rem;
  line-height: 1.7;
  padding: 1.1rem 0;
  border-bottom: 1px solid rgba(255, 255, 255, 0.1);
}

.more-info-list li:last-child {
  border-bottom: none;
}

.list-num {
  color: #6FE7B8;
  font-weight: 700;
  font-size: 0.85rem;
  letter-spacing: 1px;
  flex-shrink: 0;
  min-width: 28px;
}

/* ── RESPONSIVE ───────────────────────────────────────────── */
@media (max-width: 900px) {
  .strip-item__image       { height: 200px; }
  .strip-item--main .strip-item__image { height: 240px; }
}

@media (max-width: 600px) {
  .ns-section { padding: 48px 24px; }

  .sharp-card__header,
  .sharp-card__body,
  .sharp-card__footer,
  .info-grid,
  .sharp-card__site-row { padding-left: 1.2rem; padding-right: 1.2rem; }

  .sharp-card__footer { flex-direction: column; }
  .sharp-button       { width: 100%; text-align: center; }

  .strip-item__image       { height: 140px; }
  .strip-item--main .strip-item__image { height: 170px; }

  .strip-item__year        { font-size: 1.3rem; padding: 0.7rem; }
  .strip-item--side .strip-item__year { font-size: 1rem; }
  .strip-arrow             { font-size: 2.5rem; padding: 0 0.4rem; }
}
</style>
=======
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
>>>>>>> cad996c13c5c850727dbeb0ec5633979ebfe7ad0
