import firebase from "../firebase";
const db = firebase.ref("/Sede");
class DataService {
  getAll() {
    return db;
  }
}
export default new DataService();
