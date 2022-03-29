<template>
  <div class="Scorer">
    <div class="TwitchPlayer">
      <Stream_Player :streamer="streamer"/>
    </div>
    <div class="ScoresTables">
      <Competition_Table :file="file_link" :showColumns="columns_to_present" :showGeneral="amount_of_general_entries" :accumulation="accumulation" :accumulationField="accumulation_field"/>
    </div>
  </div>
</template>

<script>
import Competition_Table from '../components/Competition_Table'
import Stream_Player from '../components/Twitch_Player'

export default {
  name: "scores-page",
  components: {
    Competition_Table,
    Stream_Player
  },
  data(){
      return{
        file_link: "1qb9lhfV_8sIEsWBrIT49rvddlXMR3IpvBW1D5-7UriI",
        columns_to_present: ["Nome","Score"],
        amount_of_general_entries: 10,
        accumulation:true,
        accumulation_field: "IST",
        streamer: "rocketleague"
      }
    },
}
</script>

<style>
.Scorer{
  padding-top:100px;
}
.ScoresTables{
  padding-top:30px;
}
</style>
