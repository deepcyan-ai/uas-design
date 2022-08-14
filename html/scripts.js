function change(id, value){
    document.getElementById(id).readOnly=false;
    document.getElementById(id).value = value;
    document.getElementById(id).readOnly = true;
}

function batteryfill(data){
    var pvalue = document.getElementById("p").value;
    if (data.value === "type1"){
        change("cell-capacity", 1000);
        change("cell-capacity-total", (1000 * pvalue));
        change("battery-resistance", 0.00143);
        change("voltage", 3.9);
        change("c-cont", 25);
        change("c-max", 50);
        change("b-weight", 400);
        change("b-weight-oz", 14.1);
    }
    if (data.value === "type2"){
        change("cell-capacity", 1600);
        change("cell-capacity-total", (1600 * pvalue));
        change("battery-resistance", 0.00029);
        change("voltage", 3.7);
        change("c-cont", 45);
        change("c-max", 60);
        change("b-weight", 365);
        change("b-weight-oz", 12.9);
    }
    if (data.value === "type3"){
        change("cell-capacity", 2000);
        change("cell-capacity-total", (2000 * pvalue));
        change("battery-resistance", 0.001334);
        change("voltage", 3.8);
        change("c-cont", 30);
        change("c-max", 40);
        change("b-weight", 520);
        change("b-weight-oz", 18.3);
    }
}

function controllerfill(data){
    if (data.value === "type1"){
        change("a-cont", 10);
        change("a-max", 10);
        change("controller-resistance", 0.00043);
        change("c-weight", 71);
        change("c-weight-oz", 2.5);
    }
    if (data.value === "type2"){
        change("a-cont", 20);
        change("a-max", 25);
        change("controller-resistance", 0.0002);
        change("c-weight", 56);
        change("c-weight-oz", 1.97);
    }
    if (data.value === "type3"){
        change("a-cont", 30);
        change("a-max", 30);
        change("controller-resistance", 0.0009);
        change("c-weight", 93);
        change("c-weight-oz", 3.3);
    }
}

function motorfill(data){
    if (data.value === "manu-1"){
        change("rpm", 1110);
        change("NLCA", 0.55);
        change("NLCV", 8);
        change("limit", 33);
        change("motor-resistance", 0.02);
        change("cl-mm", 17);
        change("cl-inch", 0.67);
        change("magpoles", 14);
        change("m-weight", 72);
        change("m-weight-oz", 2.5);
    }
    if (data.value === "manu-2"){
        change("rpm", 1500);
        change("NLCA", 0.9);
        change("NLCV", 7.4);
        change("limit", 42.5);
        change("motor-resistance", 0.136);
        change("cl-mm", 35);
        change("cl-inch", 1.38);
        change("magpoles", 12);
        change("m-weight", 45);
        change("m-weight-oz", 1.6);
    }
    if (data.value === "manu-3"){
        change("rpm", 2000);
        change("NLCA", 0.86);
        change("NLCV", 9.3);
        change("limit", 220);
        change("motor-resistance", 0.0512);
        change("cl-mm", 22.4);
        change("cl-inch", 0.88);
        change("magpoles", 14);
        change("m-weight", 43);
        change("m-weight-oz", 1.5);
    }
}