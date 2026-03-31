import xml.etree.ElementTree as ET

class UrdfCamEditor:
    def __init__(self):
        
        ET.register_namespace("xacro", "http://www.ros.org/wiki/xacro")
        self.urdfPath = "/workspace/run/webServer/urdf/armkidd_cam.urdf.xacro"

        self.tree = None
        self.root = None


    def setCameraPose(self, camX, camY, camZ, camRot): #, xOff, yOff

        _, baseJoint, headJoint = self.findCamJointArgs()       

        updated_base = self.setXYZ(baseJoint, camX, camY, camZ)
        updated_cam = self.setRot(headJoint, camRot)

        return updated_base or updated_cam

        # if updated_base or updated_cam:
        #     self.update()
        #     return True
        
        # return False
    
    def update(self):
        self.tree.write(self.urdfPath)
        self.clear()

    def getCameraPose(self):

        _, baseJoint, headJoint = self.findCamJointArgs()

        x, y, z = self.getXYZ(baseJoint)
        rot = self.getRot(headJoint)

        return x, y, z, rot
    

    def setXYZ(self, child, x, y, z):

        xyz = child.get("xyz").split()
        xyz[0] = str(x)
        xyz[1] = str(y)
        xyz[2] = str(z)
        child.set("xyz", " ".join(xyz))

        return True

    def setRot(self, child, rot):

        rpy = child.get("rpy").split()
        rpy[1] = str(rot)  
        child.set("rpy", " ".join(rpy))

        return True

    def getXYZ(self, child):

        xyz = child.get("xyz").split()
        xOff = float(xyz[0])
        yOff = float(xyz[1])
        zOff = float(xyz[2])

        return xOff, yOff, zOff

    def getRot(self, child):

        rpy = child.get("rpy").split()
        rot = float(rpy[1])

        return rot


    def findCamJointArgs(self):

        if (self.tree == None or self.root == None):
            self.tree = ET.parse(self.urdfPath)
            self.root = self.tree.getroot()

        baseJoint = None
        headJoint = None

        for joint in self.root.iter():
            if not joint.tag.endswith("joint"):
                continue
            
            if baseJoint == None:
                baseJoint = self.getJointChild(joint, "base_link_to_torso_link")

            if headJoint == None:
                headJoint = self.getJointChild(joint, "camera_head_joint")

            if baseJoint != None and headJoint != None:
                break

        return self.tree, baseJoint, headJoint

    def getJointChild(self, joint, jointName):
        if joint.get("name") == jointName:
            for child in joint:
                if child.tag.endswith("origin"):
                    return child

    def clear(self):
        self.tree = None
        self.root = None