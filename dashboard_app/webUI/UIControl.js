
export class ModalControl{
    constructor () {
        this.parser = new DOMParser();
        this.modal = `<div class="modal fade show" style="background-color: #000000bd;" id="inputModal" tabindex="-1">
                        <div class="modal-dialog">
                            <div class="modal-content">

                            <form id="passwordForm">
                                <div class="modal-header">
                                    <h5 class="modal-title">Enter Password</h5>
                                    <button type="button" id="modal_close" class="btn-close" data-bs-dismiss="modal"></button>
                                </div>

                                <div class="modal-body">
                                    <input id="modalInput" type="password" class="form-control" required autofocus>
                                   
                                </div>

                                <div class="modal-footer">
                                    <button class="btn btn-secondary" type="button" id="modal_cancel" data-bs-dismiss="modal">Cancel</button>
                                    <button id="modalOk" type="submit" class="btn btn-primary">OK</button>
                                </div>
                            </form>

                            </div>
                        </div>
                    </div>`;
        
        this.currentNode = null;
    }                

    showModalError(show) {
        if (show) {
            document.getElementById("modalError").classList.remove("d-none");
        }
        else {
            document.getElementById("modalError").classList.add("d-none");
        }
    }

    showPopup() {        
        const doc = this.parser.parseFromString(this.modal, "text/html");        
        this.currentNode  = doc.body.firstElementChild;
        
        document.body.appendChild(this.currentNode);

        this.currentNode.style.display = "block";
        document.getElementById("modal_close").onclick = this.removePopup.bind(this);
        document.getElementById("modal_cancel").onclick = this.removePopup.bind(this);

        let form = document.getElementById("passwordForm");
        form.addEventListener("submit", e => {
            e.preventDefault(); // stop page reload

            if (!form.checkValidity()) {
                form.reportValidity(); // shows browser validation UI
                return;
            }

            const data = document.getElementById("modalInput").value;
            this.modalOk(data);
        });
    }

    modalOk = (password) => { }

    removePopup() {
        document.body.removeChild(this.currentNode);
        this.currentNode = null;
    }
}

export class SpinnerControl{
    constructor (elementSpin) {
        this.elementSpin = elementSpin;
        this.contentCache = elementSpin.innerHTML;
    }

    setSpin (msg="", setDisable=true, spinnerType="spinner-border-sm") {
        if (setDisable != null)
            this.elementSpin.disabled = setDisable;

        this.spinner = `<span class="spinner-border ${spinnerType}" role="status" aria-hidden="true"></span> ${msg}`;
        this.elementSpin.innerHTML = this.spinner;
    }

    stopSpin (setDisable=false, msg=null) {
        if (setDisable != null)
            this.elementSpin.disabled = setDisable;

        if (msg == null)
            this.elementSpin.innerHTML = this.contentCache;
        else
            this.elementSpin.innerHTML = msg;
    }
}

export class NavMenuControl{
    constructor (){

        const toggleBtnUI = `
         <button class="btn btn-primary menu-btn" id="menu_btn" type="button" data-bs-toggle="offcanvas" title="Show Menu"> 
            <span class="material-icons">
            menu
            </span>    
        </button>`;

        document.body.insertAdjacentHTML("beforeend", toggleBtnUI);        
        document.body.insertAdjacentHTML("beforeend", `<div id="menu_holder"></div>`);

        
        this.UI = `
             <div class="offcanvas offcanvas-start" tabindex="-1" id="offcanvasExample" aria-labelledby="offcanvasExampleLabel">
                <div class="offcanvas-header">
                <h5 class="offcanvas-title"> Dashboard </h5>
                <button type="button" class="btn-close" id="menu_close_btn" data-bs-dismiss="offcanvas"
                    aria-label="Close"></button>
                </div>
                <div class="offcanvas-body">
                <a href="#" class="d-flex align-items-center mb-3 mb-md-0 me-md-auto link-body-emphasis text-decoration-none">
                    <svg class="bi pe-none me-2" width="40" height="32" aria-hidden="true">
                    <use xlink:href="#bootstrap"></use>
                    </svg>
                    <span class="fs-4"> Roverlad </span>
                </a>
                <hr>
                <ul class="nav nav-pills flex-column mb-auto" id="menu_items"></ul>
                <hr>
                <div class="dropdown">
                    <a href="#" class="d-flex align-items-center link-body-emphasis text-decoration-none dropdown-toggle"
                    data-bs-toggle="dropdown" aria-expanded="false">
                    <img src="/src/RoverladPic.jpg" alt="" width="32" height="32" class="rounded-circle me-2">
                    <strong>Roverlad</strong>
                    </a>
                </div>
                </div>
            </div>
        `;       

        this.menuOn = false;

       
        document.getElementById("menu_btn").onclick = () => {
            this.toggle();
        };

        this.menuHolder = document.getElementById("menu_holder");
    }

    render() {
        this.menuHolder.innerHTML =  this.UI;

        const itemArr = [
            { name: "Mapping",    href: "/",                isActive: false, icon: "directions_car"     },
            { name: "Navigation", href: "/navigation",      isActive: false, icon: "map"                },
            { name: "Setting",    href: "/setting",         isActive: false, icon: "settings"           }
        ];

        const normalize = p => p.replace(/\/+$/, "") || "/";

        const currentPath = normalize(window.location.pathname);

        itemArr.forEach(item => {
            item.isActive = normalize(item.href) === currentPath;
        });

        document.getElementById("menu_items").innerHTML = itemArr.map(this.createMenuItem).join("");

        document.getElementById("menu_close_btn").onclick = () => {
             this.close();
        };

    }

    createMenuItem(item) {
        return `<li class="nav-item">
                    <a href="${item.href}" class="nav-link menu-item ${item.isActive ? "active" : "link-body-emphasis" }" aria-current="page">
                        <span class="material-icons">${item.icon}</span>
                        ${item.name}
                    </a>
                </li>`;        
    }

    toggle() {


        this.render();

        this.menuOn = !this.menuOn;
        // if (!this.menuObj)
        setTimeout(() => {

            this.menuObj = document.getElementById("offcanvasExample");

            if (this.menuOn)
                this.menuObj.classList.add("show");
            else
                this.menuObj.classList.remove("show");

        }, 100)
    }

    close() {
        this.menuOn = false;
        this.menuHolder.innerHTML = "";
    }

}