import firebase from "firebase/compat/app";
import "firebase/compat/database";
let config = {
    apiKey: "AIzaSyA0f8rK3e9Rrp3k1pHt_32BkFpPWUKMGWs", //FIXME esconder
    authDomain: "neec-chaves.firebaseapp.com",
    databaseURL: "https://neec-chaves-default-rtdb.europe-west1.firebasedatabase.app",
    projectId: "neec-chaves",
    storageBucket: "neec-chaves.appspot.com",
    messagingSenderId: "823950398509",
    appId: "1:823950398509:web:69d89a8b0c3219950894a4", //FIXME esconder
    measurementId: "G-GH7MC49WHG" //FIXME esconder
};
firebase.initializeApp(config);
export default firebase.database();