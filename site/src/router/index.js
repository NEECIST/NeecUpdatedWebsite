import { createRouter, createWebHistory } from 'vue-router'

import Home from '@/pages/Home'
import Error_Handling from '@/pages/Error_Handling'
import Team from '@/pages/Team'
import Oportunities from '@/pages/Oportunities'
import Projects from '@/pages/Projects'
//import Scores from '@/pages/Scores'
import Form from '@/pages/Form'
import Certificate from '@/pages/Certificate'

const routes = [
    {
        path: '/',
        name: 'Home',
        component: Home
    },
    {
        path: '/team',
        name: 'Team',
        component: Team
    },
    {
        path: '/404',
        component: Error_Handling
    },
    {
        path: '/oportunities',
        name: 'Oportunities',
        component: Oportunities
    },
    {
        path: '/projects',
        name: 'Projects',
        component: Projects
    },
    {
        path: '/form',
        name: 'Form',
        component: Form
    }, {
        path: '/certificate',
        component: Error_Handling
    }
    , {
        path: '/certificate/:id',
        name: 'Certificate',
        component: Certificate
    }
    , {
        path: '/redirect/drive',
        redirect: 'https://drive.google.com/open?id=1HjuUvki3FrK9BKkcequsfCHxNjIVtWbz'
    }

]

const router = createRouter({
    history: createWebHistory(process.env.BASE_URL),
    routes
})

export default router