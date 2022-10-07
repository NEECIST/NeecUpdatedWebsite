import firebase from "../firebase";
const db = firebase.ref("/sede/aberta");
class DataService {
  getAll() {
    return db;
  }
}
export default new DataService();
