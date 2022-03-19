const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
  VUE_APP_OPORTUNITIES_LINK: process.env.VUE_APP_OPORTUNITIES_LINK
})
