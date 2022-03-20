<template>
    <div class="about-app">
        <div class="description-about">
           <div class="about-text">
                <div class="description-title">
                    Sobre
                </div>
                <div class="description-text">
                    Descobre mais sobre o nosso núcleo e aquilo que fazemos!
                </div>
            </div>
        </div>
        <div class=about-container>
            <div class="about-card" v-for="card in aboutList" :key="card.name">
                <div class="card-title">
                    <h1> {{ card.name }} </h1>
                </div>
                <div class="card-content">
                    <p> {{ card.content }} </p>
                </div>
            </div>
        </div>

        <div class="container-title">
            <h1>Como estamos estruturados?</h1>
        </div>
        
        <div class="about-container">
            <div class="about-card" v-for="team in teamsList" :key="team.name">
                <div class="card-title">
                    <h1> {{ team.name }} </h1>
                </div>
                <div class="card-content">
                    <p> {{ team.content }} </p>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
    export default {
        name: "about-page",
        data() {
            return {
                aboutList: [
                    {
                        name: "Quem somos?",
                        content: "O NEECIST - núcleo de Estudantes de Electrotecnia e Computadores é uma associação sem fins lucrativos que reúne os estudantes de LEEC e MEEC do IST. Somos formados por alunos que, através do seu trabalho voluntário e motivados pela tecnologia e associativismo, procuram trazer novas ideias, projetos e iniciativas contribuindo para o desenvolvimnentos de todos os alunos de LEEC e MEEC."
                    },
                    {
                        name: "O que fazemos?",
                        content: "Procuramos ajudar os alunos a intregarem-se no mercado de trabalho e dar formação extra-curricular. Organizamos workshops, estágios de verão, uma hackathon e até um podcast! Tentamos proporcionar aos alunos de LEEC e de MEEC conteúdo e opurtunidades para se desenvolverem a nível académico e profissional. "
                    },
                    {
                        name: "Desde quando?",
                        content: "O NEECIST foi fundado no dia 19 de setembro de 2003, como uma associação que representasse os alunos de LEEC. A jovem associação como objetivo a união e representação dos alunos, recorrendo à organização de atividades de caráter social e profissional. Hoje, tal como no início, estes objetivos mantém-se, em conjunto com muitos outros que procuram trazer mais opurtunidades aos alunos de LEEC e MEEC."
                    }
                ],
                teamsList: [
                    {
                        name: "NEECIT",
                        content: "O NEECIT é a nossa equipa de desenvolvimento e de manutenção dos serviços do núcleo, como por exemplo a drive, o discord, e este mesmo site. Desenvolvemos também projetos mais pessoais que apresentamos na nossa banca em eventos oficiais, tais como o NEECBoto, o LevitaNEEC e o NEECQuick."
                    },
                    {
                        name: "Design",
                        content: "Design é a equipa que trata da imagem do núcleo. Utiliza ferramentas como Adobe Illustrator e Canva para fazer os nossos posts, stickers, flyers, posters, e muito mais."
                    },
                    {
                        name: "Multimédia",
                        content: "Muito como o Design, Multimédia também lida com o conteúdo que lançamos ao público mas mais focado em conteúdo vídeo. Esta é a equipa que trata dos nossos vídeos, recaps de eventos, e que organiza o nosso podcast - as NEECTalks!",
                    },
                    {
                        name: "Divulgação",
                        content: "A equipa de Divulgação é a equipa que gere as nossas redes sociais e caixa de entrada. É a equipa que contacta com o exterior e que trabalha para trazer oportunidades de estágios, bolsas, eventos, e tudo o que seja do interesse dos alunos do nosso curso.",
                    }
                ]
            }
        }
    }
</script>

<style>
    .about-app{
        margin-bottom: 20px;
    }
    .description-about {
        padding-top: 100px;
        height: 300px;
        background-color:white;
        position: relative;
    }
    .description-about img{
        width: 700px;
        /*transform: rotate(30deg);*/
        clip-path: inset(0 5.5em 4.5em 3em);
        position: absolute;
        top:100px;
        left: -60px;
        z-index: 0;
    }
    .about-text{
        float: right;
        padding-right: 40px;
        position: relative;
        z-index: 1;
    }
    .description-title{
        font-family: 'Raleway', sans-serif;
        font-size: 50px;
        font-weight: bolder;
        color: #505050;
        text-align: right;
        padding-top: 30px;
    }
    .description-text{
        margin-top: 10px;
        background-color: #009DE0;
        border-radius: 5px;
        font-size: 30px;
        font-family: 'Karla';
        width: 750px;
        padding-right: 40px;
        padding-top: 15px;
        padding-bottom: 15px;
        margin-right: -40px;
        text-align: right;
        color: #ffffff;
        line-height: 50px;
    }
    .container-title{
        color: white;
        display: block;
        margin-left: 0%;
        margin-top: 15px;
        margin-bottom: 15px;
        background-color: gray;
        padding: 20px;
    }
    .about-container{
        display: flex;
    }
    .about-card{
        margin: 20px;
        display: block;
        box-shadow: 0 4px 8px 0 rgb(0 0 0 / 20%), 0 6px 20px 0 rgb(0 0 0 / 20%);
        transition: .5s ease;
    }
    .about-card:hover{
        box-shadow: 0 14px 18px 0 rgb(0 0 0 / 20%), 0 16px 30px 0 rgb(0 0 0 / 20%);
    }
    .card-title{
        color: white;
        background-color: #009DE0;    
        padding: 20px;
        text-align: center;
    }
    .card-content{
        padding: 50px;
        max-width: 1200px;
        margin: auto;
        text-align: justify;
    }
</style>