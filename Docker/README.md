# FlowDroid & Heros Docker image
## deploy
you can deploy by typing `docker build` in this entry.
## run
`docker run -it --rm -v /PATH/TO/YOUR_APK:/opt/flowdroid YOUR_BUILT_IMAGE bash`
### flowdroid
`flowdroid /opt/flowdroid/demo.apk /opt/android-sdk-linux/platforms/android-7.0/android.jar`

### heros
In order to add an analysis, to a whole-program pack in Soot, it must be implemented as a class that extends SceneTransformer. The following is a simple example using IFDSReachingDefinitions found in Soot. IFDSReachingDefinitions was a quickly written example that is not necessarily kept up to date in Soot, and it may require corrections to properly handle special edges (usually related to Thread.run) added to the call graph by newer versions of Soot.
```java
// Subclass of SceneTransformer to run Heros IFDS solver in Soot's "wjtp" pack
public class IFDSDataFlowTransformer extends SceneTransformer {
    @Override
    protected void internalTransform(String phaseName, Map<String, String> options) {
        JimpleBasedInterproceduralCFG icfg= new JimpleBasedInterproceduralCFG();
        IFDSTabulationProblem<Unit, Pair<Value, 
                Set<DefinitionStmt>>, SootMethod, 
                InterproceduralCFG<Unit, SootMethod>> problem = new IFDSReachingDefinitions(icfg);

        IFDSSolver<Unit, Pair<Value, Set<DefinitionStmt>>, 
                SootMethod, InterproceduralCFG<Unit, SootMethod>> solver = 
                    new IFDSSolver<Unit, Pair<Value, Set<DefinitionStmt>>, SootMethod, 
                                   InterproceduralCFG<Unit, SootMethod>>(problem);

        System.out.println("Starting solver");
        solver.solve();
        System.out.println("Done");
    }
}
```
run the same way as soot.

# credit
https://github.com/FrenchYeti/flowdroid-docker