import firebase from "../firebase";
const db = firebase.ref("/sede");
class DataService {
  getAll() {
    return db;
  }
}
export default new DataService();
